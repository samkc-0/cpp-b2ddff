#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <optional>

namespace {
int failures = 0;
template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::optional<T>& value) {
    if (value.has_value()) return stream << *value;
    return stream << "std::nullopt";
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
    using stage_01::std_optional::safe_divide_exercise::safe_divide;
    try {
        EXPECT_EQUAL(safe_divide(10.0, 2.0), std::optional<double>{5.0});
        EXPECT_EQUAL(safe_divide(-9.0, 3.0), std::optional<double>{-3.0});
        EXPECT_EQUAL(safe_divide(1.0, 0.0), std::optional<double>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
