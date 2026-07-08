#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
void expect_false(bool actual, int line) { if (actual) { ++failures; std::cerr << "Line " << line << ": expected false\n"; } }
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
#define EXPECT_FALSE(actual) expect_false((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::practice::equality_operator_exercise::Point;
    try {
        EXPECT_TRUE((Point{1, 2} == Point{1, 2}));
        EXPECT_FALSE((Point{1, 2} == Point{2, 1}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
