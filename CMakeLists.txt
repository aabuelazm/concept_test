cmake_minimum_required(VERSION 3.16)

# set the project name
project(ConceptWeatherTest)

# add the executable
add_executable(ConceptWeatherTest concept_weather_test.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
