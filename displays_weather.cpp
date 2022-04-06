#include "displays_weather.hpp"

using namespace std;
using namespace concept_weather;

CurrentConditionsDisplay::CurrentConditionsDisplay(WeatherData *o)
    : station(o) {
  this->station->register_observer(this);
}

void CurrentConditionsDisplay::update() {
  this->temperature = this->station->get_temperature();
  this->humidity = this->station->get_humidity();
  this->display();
}

void CurrentConditionsDisplay::display() {
  cout << "Current conditions: " << this->temperature << "F degrees and "
       << this->humidity << "% humidity" << endl;
}

StatisticsDisplay::StatisticsDisplay(WeatherData *o) : station(o) {
  this->station->register_observer(this);
}

void StatisticsDisplay::update() {
  float temp_temperature = this->station->get_temperature();
  this->temp_sum += temp_temperature;
  this->num_readings++;

  if (temp_temperature > this->max_temp) {
    this->max_temp = temp_temperature;
  }

  if (temp_temperature < this->min_temp) {
    this->min_temp = temp_temperature;
  }

  display();
}

void StatisticsDisplay::display() {
  cout << "Avg/Max/Min temperature = " << this->temp_sum / this->num_readings
       << '/' << this->max_temp << '/' << this->min_temp << endl;
}

ForecastDisplay::ForecastDisplay(WeatherData *o) : station(o) {
  this->station->register_observer(this);
}

void ForecastDisplay::update() {
  this->last_pressure = this->current_pressure;
  this->current_pressure = this->station->get_pressure();

  this->display();
}

void ForecastDisplay::display() {
  cout << "Forecast: ";
  if (this->current_pressure > this->last_pressure)
    cout << "Improving weather on the way!";
  else if (this->current_pressure == this->last_pressure)
    cout << "More of the same";
  else if (this->current_pressure < this->last_pressure)
    cout << "Watch out for cooler, rainy weather";
  cout << endl;
}
