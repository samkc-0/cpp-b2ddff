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
        std::cerr << "Line " << line << ": expected " << expected << ", got " << actual << "\n";
    }
}

#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)

}  // namespace

int main() {
    using stage_01::std_string::count_words_exercise::count_words;

    try {
        EXPECT_EQUAL(count_words("one two three"), 3U);
        EXPECT_EQUAL(count_words("  leading and   repeated spaces  "), 4U);
        EXPECT_EQUAL(count_words("single"), 1U);
        EXPECT_EQUAL(count_words(""), 0U);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
