#include "exercise.hpp"

#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <optional>

namespace {
int failures = 0;
std::ostream& operator<<(std::ostream& stream, const std::optional<double>& value) {
    if (value.has_value()) return stream << *value;
    return stream << "std::nullopt";
}
void expect_optional_near(const std::optional<double>& actual, const std::optional<double>& expected, int line) {
    if (actual.has_value() != expected.has_value() ||
        (actual.has_value() && std::fabs(*actual - *expected) > 0.000001)) {
        ++failures;
        std::cerr << "Line " << line << ": expected " << expected << ", got " << actual << "\n";
    }
}
#define EXPECT_OPTIONAL_NEAR(actual, expected) expect_optional_near((actual), (expected), __LINE__)
}  // namespace

int main() {
    using stage_01::std_optional::parse_double_exercise::parse_double;
    try {
        EXPECT_OPTIONAL_NEAR(parse_double("3.5"), std::optional<double>{3.5});
        EXPECT_OPTIONAL_NEAR(parse_double("-0.25"), std::optional<double>{-0.25});
        EXPECT_OPTIONAL_NEAR(parse_double("3.5x"), std::optional<double>{});
        EXPECT_OPTIONAL_NEAR(parse_double(""), std::optional<double>{});
        EXPECT_OPTIONAL_NEAR(parse_double(" 3.5"), std::optional<double>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
