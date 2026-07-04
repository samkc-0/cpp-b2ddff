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
    using stage_01::std_string::replace_all_exercise::replace_all;

    try {
        EXPECT_EQUAL(replace_all("one fish two fish", "fish", "cat"), std::string("one cat two cat"));
        EXPECT_EQUAL(replace_all("aaaa", "aa", "b"), std::string("bb"));
        EXPECT_EQUAL(replace_all("abc", "", "x"), std::string("abc"));
        EXPECT_EQUAL(replace_all("abc", "z", "x"), std::string("abc"));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
