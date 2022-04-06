#include "displays_weather.hpp"

using namespace std;
using namespace concept_weather;

class CurrentConditionsDisplay : virtual public DisplayElement,
                                 virtual public Observer {
private:
  float temperature{};
  float humidity{};
  WeatherData *station = nullptr;

public:
  CurrentConditionsDisplay(WeatherData *o) : station(o) {
    station->register_observer(this);
  }

  void update() {
    temperature = station->get_temperature();
    humidity = station->get_humidity();
    display();
  }

  void display() {
    cout << "Current conditions: " << temperature << "F degrees and "
         << humidity << "% humidity" << endl;
  }
};

class StatisticsDisplay : virtual public Observer,
                          virtual public DisplayElement {
private:
  float max_temp{};
  float min_temp{200};
  float temp_sum{};

  int num_readings{};
  WeatherData *station = nullptr;

public:
  StatisticsDisplay(WeatherData *o) : station(o) {
    station->register_observer(this);
  }

  void update() {
    float temp_temperature = station->get_temperature();
    temp_sum += temp_temperature;
    num_readings++;

    if (temp_temperature > max_temp) {
      max_temp = temp_temperature;
    }

    if (temp_temperature < min_temp) {
      min_temp = temp_temperature;
    }

    display();
  }

  void display() {
    cout << "Avg/Max/Min temperature = " << temp_sum / num_readings << '/'
         << max_temp << '/' << min_temp << endl;
  }
};

class ForecastDisplay : virtual public Observer, virtual public DisplayElement {
private:
  float current_pressure{29.92};
  float last_pressure{};
  WeatherData *station = nullptr;

public:
  ForecastDisplay(WeatherData *o) : station(o) {
    station->register_observer(this);
  }

  void update() {
    last_pressure = current_pressure;
    current_pressure = station->get_pressure();

    display();
  }

  void display() {
    cout << "Forecast: ";
    if (current_pressure > last_pressure)
      cout << "Improving weather on the way!";
    else if (current_pressure == last_pressure)
      cout << "More of the same";
    else if (current_pressure < last_pressure)
      cout << "Watch out for cooler, rainy weather";
    cout << endl;
  }
};
