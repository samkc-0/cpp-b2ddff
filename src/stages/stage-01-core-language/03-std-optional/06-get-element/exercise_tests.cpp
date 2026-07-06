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
    using stage_01::std_optional::get_element_exercise::get_element;
    try {
        EXPECT_EQUAL(get_element({10, 20, 30}, 0), std::optional<int>{10});
        EXPECT_EQUAL(get_element({10, 20, 30}, 2), std::optional<int>{30});
        EXPECT_EQUAL(get_element({10, 20, 30}, 3), std::optional<int>{});
        EXPECT_EQUAL(get_element({}, 0), std::optional<int>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
