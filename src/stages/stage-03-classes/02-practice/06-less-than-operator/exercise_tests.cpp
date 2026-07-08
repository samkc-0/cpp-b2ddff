#include "exercise.hpp"

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

namespace {
int failures = 0;
template <typename A, typename E>
void expect_equal(const A& actual, const E& expected, int line) {
    if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; }
}
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
}  // namespace

int main() {
    using stage_03::practice::less_than_operator_exercise::Task;
    try {
        std::vector<Task> tasks{{"b", 2}, {"a", 1}, {"c", 1}};
        std::sort(tasks.begin(), tasks.end());
        EXPECT_EQUAL(tasks[0].title(), std::string("a"));
        EXPECT_EQUAL(tasks[1].title(), std::string("c"));
        EXPECT_EQUAL(tasks[2].title(), std::string("b"));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
