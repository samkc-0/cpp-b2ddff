#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

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
    using stage_01::std_string::join_strings_exercise::join_strings;

    try {
        EXPECT_EQUAL(join_strings({"red", "green", "blue"}, ", "), std::string("red, green, blue"));
        EXPECT_EQUAL(join_strings({"one"}, ", "), std::string("one"));
        EXPECT_EQUAL(join_strings({}, ", "), std::string(""));
        EXPECT_EQUAL(join_strings({"a", "b", "c"}, ""), std::string("abc"));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
