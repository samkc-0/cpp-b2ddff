#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <optional>
#include <string>

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
    using stage_01::std_optional::lookup_in_map_exercise::lookup_in_map;
    const std::map<std::string, int> ages{{"Ada", 36}, {"Bjarne", 74}, {"Grace", 85}};

    try {
        EXPECT_EQUAL(lookup_in_map(ages, "Ada"), std::optional<int>{36});
        EXPECT_EQUAL(lookup_in_map(ages, "Grace"), std::optional<int>{85});
        EXPECT_EQUAL(lookup_in_map(ages, "Linus"), std::optional<int>{});
        EXPECT_EQUAL(lookup_in_map({}, "Ada"), std::optional<int>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
