#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

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
    using stage_01::references_const::contains_word_exercise::contains_word;
    try {
        EXPECT_TRUE(contains_word({"red", "green", "blue"}, "green"));
        EXPECT_FALSE(contains_word({"red", "green", "blue"}, "yellow"));
        EXPECT_FALSE(contains_word({}, "green"));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
