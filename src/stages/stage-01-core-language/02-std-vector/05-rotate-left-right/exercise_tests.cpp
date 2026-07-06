#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>

namespace {
int failures = 0;
std::ostream& operator<<(std::ostream& stream, const std::vector<int>& values) {
    stream << "{";
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i != 0) stream << ", ";
        stream << values[i];
    }
    return stream << "}";
}
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) {
    if (!(actual == expected)) {
        ++failures;
        std::cerr << "Line " << line << ": expected " << expected << ", got " << actual << "\n";
    }
}
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
}  // namespace

int main() {
    using stage_01::std_vector::rotate_left_right_exercise::rotate_left;
    using stage_01::std_vector::rotate_left_right_exercise::rotate_right;
    try {
        EXPECT_EQUAL(rotate_left({1, 2, 3, 4}, 1), std::vector<int>({2, 3, 4, 1}));
        EXPECT_EQUAL(rotate_left({1, 2, 3, 4}, 6), std::vector<int>({3, 4, 1, 2}));
        EXPECT_EQUAL(rotate_right({1, 2, 3, 4}, 1), std::vector<int>({4, 1, 2, 3}));
        EXPECT_EQUAL(rotate_right({}, 3), std::vector<int>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
