#ifndef DATA_WEATHER_HPP
#define DATA_WEATHER_HPP

#include "concept_weather.hpp"

namespace concept_weather {
class WeatherData : virtual public Subject {
private:
  float temperature{};
  float humidity{};
  float pressure{};

public:
  WeatherData() {}

  void set_measurements(float temp, float hum, float press) {
    temperature = temp;
    humidity = hum;
    pressure = press;
    notify_observers();
  }

  float get_temperature() { return temperature; }
  float get_humidity() { return humidity; }
  float get_pressure() { return pressure; }
};
} // namespace concept_weather

#endif
