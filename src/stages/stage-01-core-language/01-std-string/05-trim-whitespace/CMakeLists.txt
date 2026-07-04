add_library(stage_01_std_string_05_trim_whitespace
    exercise.cpp
)

target_include_directories(stage_01_std_string_05_trim_whitespace PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(stage_01_std_string_05_trim_whitespace_tests
    exercise_tests.cpp
)

target_link_libraries(stage_01_std_string_05_trim_whitespace_tests PRIVATE stage_01_std_string_05_trim_whitespace)

add_test(
    NAME stage_01_std_string_05_trim_whitespace
    COMMAND stage_01_std_string_05_trim_whitespace_tests
)
