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
    using stage_01::std_optional::find_key_by_value_exercise::find_key_by_value;
    const std::map<std::string, int> scores{{"Ada", 100}, {"Bjarne", 95}, {"Grace", 100}};

    try {
        EXPECT_EQUAL(find_key_by_value(scores, 95), std::optional<std::string>{"Bjarne"});
        EXPECT_EQUAL(find_key_by_value(scores, 100), std::optional<std::string>{"Ada"});
        EXPECT_EQUAL(find_key_by_value(scores, 50), std::optional<std::string>{});
        EXPECT_EQUAL(find_key_by_value({}, 100), std::optional<std::string>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
