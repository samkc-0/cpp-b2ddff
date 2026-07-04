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
        std::cerr << "Line " << line << ": assertion failed\n";
    }
}

#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)

}  // namespace

int main() {
    using stage_01::std_string::split_on_spaces_exercise::split_on_spaces;

    try {
        EXPECT_EQUAL(split_on_spaces("alpha beta gamma"), std::vector<std::string>({"alpha", "beta", "gamma"}));
        EXPECT_EQUAL(split_on_spaces("  alpha   beta  "), std::vector<std::string>({"alpha", "beta"}));
        EXPECT_EQUAL(split_on_spaces("single"), std::vector<std::string>({"single"}));
        EXPECT_EQUAL(split_on_spaces(""), std::vector<std::string>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
