#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

namespace {
int failures = 0;
template <typename A, typename E>
void expect_equal(const A& actual, const E& expected, int line) {
    if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; }
}
void expect_false(bool actual, int line) { if (actual) { ++failures; std::cerr << "Line " << line << ": expected false\n"; } }
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_FALSE(actual) expect_false((actual), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::practice::const_methods_exercise::Label;
    try {
        const Label label{"hello"};
        EXPECT_EQUAL(label.text(), std::string("hello"));
        EXPECT_EQUAL(label.length(), 5U);
        EXPECT_FALSE(label.is_empty());
        Label mutable_label{"x"};
        mutable_label.clear();
        EXPECT_TRUE(mutable_label.is_empty());
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
