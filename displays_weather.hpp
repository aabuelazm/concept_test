#ifndef DISPLAYS_WEATHER_HPP
#define DISPLAYS_WEATHER_HPP

#include "data_weather.hpp"
#include <iostream>

namespace concept_weather {
class CurrentConditionsDisplay : virtual public Observer,
                                 virtual public DisplayElement {
private:
  float temperature{};
  float humidity{};
  WeatherData *station{};

public:
  CurrentConditionsDisplay(WeatherData *o);
  void update();
  void display();
};

class StatisticsDisplay : virtual public Observer,
                          virtual public DisplayElement {
private:
  float max_temp{};
  float min_temp{};
  float temp_sum{};

  int num_readings{};
  WeatherData *station{};

public:
  StatisticsDisplay(WeatherData *o);
  void update();
  void display();
};

class ForecastDisplay : virtual public Observer, virtual public DisplayElement {
private:
  float current_pressure{};
  float last_pressure{};
  WeatherData *station{};

public:
  ForecastDisplay(WeatherData *o);
  void update();
  void display();
};
} // namespace concept_weather

#endif
