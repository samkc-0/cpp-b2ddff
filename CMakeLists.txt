cmake_minimum_required(VERSION 3.16)

project(cpp_curriculum_exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(src/stages/stage-01-core-language/01-std-string)
add_subdirectory(src/stages/stage-01-core-language/02-std-vector)
