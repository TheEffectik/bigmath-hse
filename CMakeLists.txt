cmake_minimum_required(VERSION 3.22)
project(bignum)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include_directories(main_lib)
add_subdirectory(main_lib)

# target_link_libraries(main_lib main_lib)

add_subdirectory(Google_tests)