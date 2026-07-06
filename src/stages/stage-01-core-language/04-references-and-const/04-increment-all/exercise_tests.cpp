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
    using stage_01::references_const::increment_all_exercise::increment_all;
    try {
        std::vector<int> values{1, -2, 0};
        increment_all(values);
        EXPECT_EQUAL(values, std::vector<int>({2, -1, 1}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
