#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
template <typename A, typename E>
void expect_equal(const A& actual, const E& expected, int line) {
    if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; }
}
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::practice::compound_assignment_exercise::Counter;
    try {
        Counter counter{3};
        (counter += 4) += 5;
        EXPECT_EQUAL(counter.value(), 12);
        EXPECT_TRUE((counter == Counter{12}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
