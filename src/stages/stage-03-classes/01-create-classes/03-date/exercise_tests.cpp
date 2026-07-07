#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

namespace {
int failures = 0;
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) {
    if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; }
}
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::date_exercise::Date;
    try {
        const Date date{2026, 7, 7};
        EXPECT_EQUAL(date.year(), 2026);
        EXPECT_EQUAL(date.month(), 7);
        EXPECT_EQUAL(date.day(), 7);
        EXPECT_EQUAL(date.to_iso_string(), std::string("2026-07-07"));
        EXPECT_TRUE((Date{2026, 7, 7} == Date{2026, 7, 7}));
        EXPECT_TRUE((Date{2026, 7, 7} < Date{2026, 7, 8}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
