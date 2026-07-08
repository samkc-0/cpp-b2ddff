#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

namespace {
int failures = 0;
template <typename A, typename E>
void expect_equal(const A& actual, const E& expected, int line) {
    if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; }
}
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
}  // namespace

int main() {
    using stage_03::practice::stream_output_operator_exercise::NameTag;
    try {
        std::ostringstream out;
        out << NameTag{"Ada", "Lovelace"};
        EXPECT_EQUAL(out.str(), std::string("Ada Lovelace"));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
