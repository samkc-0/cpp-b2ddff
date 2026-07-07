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
    using stage_03::classes::stopwatch_exercise::Stopwatch;
    try {
        Stopwatch watch;
        EXPECT_EQUAL(watch.elapsed_seconds(), 0);
        EXPECT_FALSE(watch.is_running());
        watch.start();
        watch.tick(5);
        EXPECT_TRUE(watch.is_running());
        EXPECT_EQUAL(watch.elapsed_seconds(), 5);
        watch.stop();
        watch.tick(5);
        EXPECT_EQUAL(watch.elapsed_seconds(), 5);
        watch.reset();
        EXPECT_EQUAL(watch.elapsed_seconds(), 0);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
