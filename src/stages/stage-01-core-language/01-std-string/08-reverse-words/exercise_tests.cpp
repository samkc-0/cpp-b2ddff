#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

namespace {

int failures = 0;

template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) {
    if (!(actual == expected)) {
        ++failures;
        std::cerr << "Line " << line << ": expected \"" << expected << "\", got \"" << actual << "\"\n";
    }
}

#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)

}  // namespace

int main() {
    using stage_01::std_string::reverse_words_exercise::reverse_words;

    try {
        EXPECT_EQUAL(reverse_words("one two three"), std::string("three two one"));
        EXPECT_EQUAL(reverse_words("  keep   spacing simple "), std::string("simple spacing keep"));
        EXPECT_EQUAL(reverse_words("single"), std::string("single"));
        EXPECT_EQUAL(reverse_words(""), std::string(""));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
