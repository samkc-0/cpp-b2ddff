#include "exercise.hpp"

#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>

namespace {
int failures = 0;
std::ostream& operator<<(std::ostream& stream, const std::vector<double>& values) {
    stream << "{";
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i != 0) stream << ", ";
        stream << values[i];
    }
    return stream << "}";
}
void expect_near_vector(const std::vector<double>& actual, const std::vector<double>& expected, int line) {
    if (actual.size() != expected.size()) {
        ++failures;
        std::cerr << "Line " << line << ": expected " << expected << ", got " << actual << "\n";
        return;
    }
    for (std::size_t i = 0; i < actual.size(); ++i) {
        if (std::fabs(actual[i] - expected[i]) > 0.000001) {
            ++failures;
            std::cerr << "Line " << line << ": expected " << expected << ", got " << actual << "\n";
            return;
        }
    }
}
#define EXPECT_NEAR_VECTOR(actual, expected) expect_near_vector((actual), (expected), __LINE__)
}  // namespace

int main() {
    using stage_01::references_const::scale_values_exercise::scale_values;
    try {
        EXPECT_NEAR_VECTOR(scale_values({1.5, -2.0, 4.0}, 2.0), std::vector<double>({3.0, -4.0, 8.0}));
        EXPECT_NEAR_VECTOR(scale_values({}, 2.0), std::vector<double>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
