#include "exercise.hpp"

#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
void expect_near(double actual, double expected, int line) { if (std::fabs(actual - expected) > 0.000001) { ++failures; std::cerr << "Line " << line << ": expected " << expected << ", got " << actual << "\n"; } }
#define EXPECT_NEAR(actual, expected) expect_near((actual), (expected), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::circle_exercise::Circle;
    try {
        const Circle circle{2.0};
        EXPECT_NEAR(circle.radius(), 2.0);
        EXPECT_NEAR(circle.diameter(), 4.0);
        EXPECT_NEAR(circle.circumference(), 12.566370614359172);
        EXPECT_NEAR(circle.area(), 12.566370614359172);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
