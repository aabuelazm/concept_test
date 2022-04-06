cmake_minimum_required(VERSION 3.16)

# set the project name
project(ConceptWeatherTest)

# find sources here
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -iquote ${PROJECT_SOURCE_DIR}")

# set sources here
set(SOURCES concept_weather_test.cpp concept_weather.hpp data_weather.hpp displays_weather.cpp displays_weather.hpp)

# add the executable
add_executable(ConceptWeatherTest ${SOURCES})
