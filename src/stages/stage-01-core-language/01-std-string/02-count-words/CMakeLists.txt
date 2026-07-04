add_library(stage_01_std_string_02_count_words
    exercise.cpp
)

target_include_directories(stage_01_std_string_02_count_words PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(stage_01_std_string_02_count_words_tests
    exercise_tests.cpp
)

target_link_libraries(stage_01_std_string_02_count_words_tests PRIVATE stage_01_std_string_02_count_words)

add_test(
    NAME stage_01_std_string_02_count_words
    COMMAND stage_01_std_string_02_count_words_tests
)
