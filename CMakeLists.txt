cmake_minimum_required(VERSION 3.27)
project(bignum)

set(CMAKE_CXX_STANDARD 17)

include_directories(main_lib)
add_subdirectory(main_lib)

add_subdirectory(Google_tests)