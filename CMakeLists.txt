cmake_minimum_required(VERSION 3.27)
project(math)

set(CMAKE_CXX_STANDARD 17)

add_library(main_lib STATIC main_lib/library.cpp)

add_subdirectory(Google_tests)