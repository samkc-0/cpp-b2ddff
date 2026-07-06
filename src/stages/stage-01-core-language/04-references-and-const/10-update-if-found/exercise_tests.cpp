#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <string>

namespace {
int failures = 0;
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) {
    if (!(actual == expected)) {
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
void expect_false(bool actual, int line) {
    if (actual) {
        ++failures;
        std::cerr << "Line " << line << ": expected false, got true\n";
    }
}
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
#define EXPECT_FALSE(actual) expect_false((actual), __LINE__)
}  // namespace

int main() {
    using stage_01::references_const::update_if_found_exercise::update_if_found;
    try {
        std::map<std::string, int> values{{"Ada", 36}, {"Bjarne", 74}};
        EXPECT_TRUE(update_if_found(values, "Ada", 37));
        EXPECT_EQUAL(values.at("Ada"), 37);
        EXPECT_FALSE(update_if_found(values, "Grace", 85));
        EXPECT_EQUAL(values.size(), 2U);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
