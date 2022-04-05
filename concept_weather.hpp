#ifndef CONCEPT_WEATHER_HPP
#define CONCEPT_WEATHER_HPP2

#include <algorithm>
#include <vector>

namespace concept_weather {
class Observer {
public:
  virtual void update();
};

class Subject {
protected:
  std::vector<Observer *> observers{};

public:
  void register_observer(Observer *o) { observers.push_back(o); }

  void remove_observer(Observer *o) {
    observers.erase(std::find(observers.begin(), observers.end(), o));
  }

  void notify_observers() {
    for (auto o : observers) {
      o->update();
    }
  }
};

class DisplayElement {
public:
  virtual void display();
};
} // namespace concept_weather

#endif
