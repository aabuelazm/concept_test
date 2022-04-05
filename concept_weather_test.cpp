#include "displays_weather.hpp"
using namespace concept_weather;
using namespace std;

int main() {
  auto *weather_data = new WeatherData;

  auto *current_display = new CurrentConditionsDisplay(weather_data);
  auto *statistic_display = new StatisticsDisplay(weather_data);
  auto *forecast_display = new ForecastDisplay(weather_data);

  weather_data->set_measurements(80, 65, 30.4);
  weather_data->set_measurements(82, 70, 29.2);
  weather_data->set_measurements(78, 90, 29.2);
}
