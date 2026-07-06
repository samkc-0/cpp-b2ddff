#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

namespace {
int failures = 0;
std::ostream& operator<<(std::ostream& stream, const std::vector<std::string>& values) {
    stream << "{";
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i != 0) stream << ", ";
        stream << '"' << values[i] << '"';
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
    using stage_01::references_const::append_suffix_exercise::append_suffix;
    try {
        std::vector<std::string> words{"cat", "dog"};
        append_suffix(words, "s");
        EXPECT_EQUAL(words, std::vector<std::string>({"cats", "dogs"}));
        append_suffix(words, "");
        EXPECT_EQUAL(words, std::vector<std::string>({"cats", "dogs"}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
