# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(googletest/include googletest)

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run test_of_casts.cpp
        add.cpp
        div.cpp
        comparing.cpp)

target_link_libraries(Google_Tests_run main_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)