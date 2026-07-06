#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

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
    using stage_01::references_const::longest_string_exercise::longest_string;
    try {
        EXPECT_EQUAL(longest_string({"red", "green", "blue"}), std::optional<std::string_view>{"green"});
        EXPECT_EQUAL(longest_string({"first", "equal"}), std::optional<std::string_view>{"first"});
        EXPECT_EQUAL(longest_string({}), std::optional<std::string_view>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
