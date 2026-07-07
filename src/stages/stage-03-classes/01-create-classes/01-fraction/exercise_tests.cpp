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
void expect_true(bool actual, int line) {
    if (!actual) {
        ++failures;
        std::cerr << "Line " << line << ": expected true, got false\n";
    }
}
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::fraction_exercise::Fraction;
    try {
        const Fraction half{2, 4};
        EXPECT_EQUAL(half.numerator(), 1);
        EXPECT_EQUAL(half.denominator(), 2);
        EXPECT_TRUE((Fraction{1, 2} == Fraction{2, 4}));
        EXPECT_TRUE(((Fraction{1, 2} + Fraction{1, 3}) == Fraction{5, 6}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
