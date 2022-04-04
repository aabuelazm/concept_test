#ifndef CONCEPT_WEATHER_HPP
#define CONCEPT_WEATHER_HPP
#include <concepts>

namespace concept_weather {
  template<class T>
  concept Subject = requires(T subject_class) {
    subject_class.register_observer();
    subject_class.remove_observer();
    subject_class.notify_observer();
  };

  template<class T>
  concept Observer = requires(T observer_class) {
    observer_class.update();
  };

  template<class T>
  concept DisplayElement = requires(T display_class) {
    display_class.display();
  };
}

#endif
