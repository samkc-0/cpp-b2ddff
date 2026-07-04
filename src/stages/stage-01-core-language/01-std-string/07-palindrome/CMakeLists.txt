add_library(stage_01_std_string_07_palindrome
    exercise.cpp
)

target_include_directories(stage_01_std_string_07_palindrome PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(stage_01_std_string_07_palindrome_tests
    exercise_tests.cpp
)

target_link_libraries(stage_01_std_string_07_palindrome_tests PRIVATE stage_01_std_string_07_palindrome)

add_test(
    NAME stage_01_std_string_07_palindrome
    COMMAND stage_01_std_string_07_palindrome_tests
)
