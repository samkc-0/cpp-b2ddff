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
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
}  // namespace

int main() {
    using stage_03::practice::initialization_list_exercise::UserProfile;
    try {
        const UserProfile profile{"sam", 42};
        EXPECT_EQUAL(profile.username(), std::string("sam"));
        EXPECT_EQUAL(profile.reputation(), 42);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
