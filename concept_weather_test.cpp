#include "displays_weather.hpp"
using namespace concept_weather;
using namespace std;

int main() {
  auto *weather_data = new WeatherData;

  new CurrentConditionsDisplay(weather_data);
  new StatisticsDisplay(weather_data);
  new ForecastDisplay(weather_data);

  weather_data->set_measurements(80, 65, 30.4);
  weather_data->set_measurements(82, 70, 29.2);
  weather_data->set_measurements(78, 90, 29.2);
}
