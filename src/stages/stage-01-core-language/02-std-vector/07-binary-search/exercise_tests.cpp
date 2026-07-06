#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
void expect_true(bool actual, int line) {
    if (!actual) {
        ++failures;
        std::cerr << "Line " << line << ": expected true, got false\n";
    }
}
void expect_false(bool actual, int line) {
    if (actual) {
        ++failures;
        std::cerr << "Line " << line << ": expected false, got true\n";
    }
}
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
#define EXPECT_FALSE(actual) expect_false((actual), __LINE__)
}  // namespace

int main() {
    using stage_01::std_vector::binary_search_exercise::binary_search_manual;
    try {
        EXPECT_TRUE(binary_search_manual({1, 3, 5, 7, 9}, 1));
        EXPECT_TRUE(binary_search_manual({1, 3, 5, 7, 9}, 7));
        EXPECT_FALSE(binary_search_manual({1, 3, 5, 7, 9}, 4));
        EXPECT_FALSE(binary_search_manual({}, 4));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
