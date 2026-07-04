cmake_minimum_required(VERSION 3.16)

project(cpp_stage_01_core_language LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(stage01_exercises
    src/exercises.cpp
)

target_include_directories(stage01_exercises PUBLIC include)

add_executable(stage01_tests
    tests/stage01_tests.cpp
)

target_link_libraries(stage01_tests PRIVATE stage01_exercises)

enable_testing()
add_test(NAME stage01_all COMMAND stage01_tests)
