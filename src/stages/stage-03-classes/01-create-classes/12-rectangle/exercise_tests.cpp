#include "exercise.hpp"

#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
void expect_near(double actual, double expected, int line) { if (std::fabs(actual - expected) > 0.000001) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; } }
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
void expect_false(bool actual, int line) { if (actual) { ++failures; std::cerr << "Line " << line << ": expected false\n"; } }
#define EXPECT_NEAR(actual, expected) expect_near((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
#define EXPECT_FALSE(actual) expect_false((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::rectangle_exercise::Rectangle;
    try {
        const Rectangle rectangle{3.0, 4.0};
        EXPECT_NEAR(rectangle.area(), 12.0);
        EXPECT_NEAR(rectangle.perimeter(), 14.0);
        EXPECT_FALSE(rectangle.is_square());
        EXPECT_TRUE((Rectangle{5.0, 5.0}.is_square()));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
