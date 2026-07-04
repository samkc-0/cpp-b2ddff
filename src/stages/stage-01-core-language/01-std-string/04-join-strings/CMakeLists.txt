add_library(stage_01_std_string_04_join_strings
    exercise.cpp
)

target_include_directories(stage_01_std_string_04_join_strings PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(stage_01_std_string_04_join_strings_tests
    exercise_tests.cpp
)

target_link_libraries(stage_01_std_string_04_join_strings_tests PRIVATE stage_01_std_string_04_join_strings)

add_test(
    NAME stage_01_std_string_04_join_strings
    COMMAND stage_01_std_string_04_join_strings_tests
)
