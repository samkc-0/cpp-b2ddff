#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>

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
    using stage_01::std_vector::sum_elements_exercise::sum_elements;
    try {
        EXPECT_EQUAL(sum_elements({1, 2, 3, 4}), 10);
        EXPECT_EQUAL(sum_elements({-2, 5, -3}), 0);
        EXPECT_EQUAL(sum_elements({}), 0);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
