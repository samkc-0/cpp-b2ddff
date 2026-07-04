add_library(stage_01_std_string_06_replace_all
    exercise.cpp
)

target_include_directories(stage_01_std_string_06_replace_all PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(stage_01_std_string_06_replace_all_tests
    exercise_tests.cpp
)

target_link_libraries(stage_01_std_string_06_replace_all_tests PRIVATE stage_01_std_string_06_replace_all)

add_test(
    NAME stage_01_std_string_06_replace_all
    COMMAND stage_01_std_string_06_replace_all_tests
)
