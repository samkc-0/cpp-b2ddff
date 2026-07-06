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
    using stage_01::std_optional::parse_integer_exercise::parse_integer;
    try {
        EXPECT_EQUAL(parse_integer("42"), std::optional<int>{42});
        EXPECT_EQUAL(parse_integer("-17"), std::optional<int>{-17});
        EXPECT_EQUAL(parse_integer("12x"), std::optional<int>{});
        EXPECT_EQUAL(parse_integer(""), std::optional<int>{});
        EXPECT_EQUAL(parse_integer(" 42"), std::optional<int>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
