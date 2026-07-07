#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) { if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; } }
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
void expect_false(bool actual, int line) { if (actual) { ++failures; std::cerr << "Line " << line << ": expected false\n"; } }
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
#define EXPECT_FALSE(actual) expect_false((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::timer_exercise::Timer;
    try {
        Timer timer{10};
        EXPECT_EQUAL(timer.remaining_seconds(), 10);
        EXPECT_FALSE(timer.is_finished());
        timer.tick(4);
        EXPECT_EQUAL(timer.remaining_seconds(), 6);
        timer.tick(10);
        EXPECT_EQUAL(timer.remaining_seconds(), 0);
        EXPECT_TRUE(timer.is_finished());
        timer.reset();
        EXPECT_EQUAL(timer.remaining_seconds(), 10);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
