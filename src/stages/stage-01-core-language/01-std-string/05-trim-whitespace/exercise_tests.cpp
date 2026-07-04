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
        std::cerr << "Line " << line << ": assertion failed\n";
    }
}

#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)

}  // namespace

int main() {
    using stage_01::std_string::trim_whitespace_exercise::trim_whitespace;

    try {
        EXPECT_EQUAL(trim_whitespace("  hello  "), std::string("hello"));
        EXPECT_EQUAL(trim_whitespace("\t spaced words \n"), std::string("spaced words"));
        EXPECT_EQUAL(trim_whitespace("   "), std::string(""));
        EXPECT_EQUAL(trim_whitespace("already clean"), std::string("already clean"));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
