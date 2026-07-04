#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

namespace {

int failures = 0;

template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) {
    if (!(actual == expected)) {
        ++failures;
        std::cerr << "Line " << line << ": assertion failed\n";
    }
}

#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)

}  // namespace

int main() {
    using stage_01::std_string::count_vowels_exercise::count_vowels;

    try {
        EXPECT_EQUAL(count_vowels("hello world"), 3U);
        EXPECT_EQUAL(count_vowels("AEIOU and sometimes y"), 10U);
        EXPECT_EQUAL(count_vowels("rhythm"), 0U);
        EXPECT_EQUAL(count_vowels(""), 0U);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
