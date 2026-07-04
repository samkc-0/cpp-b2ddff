cmake_minimum_required(VERSION 3.16)

project(cpp_iterables_exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(iterables_tests
    tests/iterables_tests.cpp
)

target_include_directories(iterables_tests PRIVATE include)

enable_testing()
add_test(NAME iterables_all COMMAND iterables_tests)
