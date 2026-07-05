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
    using stage_01::std_string::palindrome_exercise::is_palindrome;

    try {
        EXPECT_TRUE(is_palindrome("racecar"));
        EXPECT_TRUE(is_palindrome("A man, a plan, a canal: Panama"));
        EXPECT_TRUE(is_palindrome(""));
        EXPECT_FALSE(is_palindrome("hello"));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
