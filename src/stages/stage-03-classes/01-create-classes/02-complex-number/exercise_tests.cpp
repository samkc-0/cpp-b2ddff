#include "exercise.hpp"

#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
void expect_near(double actual, double expected, int line) {
    if (std::fabs(actual - expected) > 0.000001) {
        ++failures;
        std::cerr << "Line " << line << ": expected " << expected << ", got " << actual << "\n";
    }
}
void expect_true(bool actual, int line) {
    if (!actual) {
        ++failures;
        std::cerr << "Line " << line << ": expected true, got false\n";
    }
}
#define EXPECT_NEAR(actual, expected) expect_near((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::complex_number_exercise::ComplexNumber;
    try {
        const ComplexNumber value{3.0, 4.0};
        EXPECT_NEAR(value.real(), 3.0);
        EXPECT_NEAR(value.imaginary(), 4.0);
        EXPECT_NEAR(value.magnitude(), 5.0);
        EXPECT_TRUE(((ComplexNumber{1.0, 2.0} + ComplexNumber{3.0, 4.0}) == ComplexNumber{4.0, 6.0}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
