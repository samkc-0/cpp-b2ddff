add_library(stage_01_std_string_03_split_on_spaces
    exercise.cpp
)

target_include_directories(stage_01_std_string_03_split_on_spaces PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(stage_01_std_string_03_split_on_spaces_tests
    exercise_tests.cpp
)

target_link_libraries(stage_01_std_string_03_split_on_spaces_tests PRIVATE stage_01_std_string_03_split_on_spaces)

add_test(
    NAME stage_01_std_string_03_split_on_spaces
    COMMAND stage_01_std_string_03_split_on_spaces_tests
)
