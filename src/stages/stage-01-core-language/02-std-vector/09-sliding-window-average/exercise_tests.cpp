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
    using stage_01::std_vector::sliding_window_average_exercise::sliding_window_average;
    try {
        EXPECT_NEAR_VECTOR(sliding_window_average({1.0, 2.0, 3.0, 4.0}, 2), std::vector<double>({1.5, 2.5, 3.5}));
        EXPECT_NEAR_VECTOR(sliding_window_average({2.0, 4.0, 6.0}, 3), std::vector<double>({4.0}));
        EXPECT_NEAR_VECTOR(sliding_window_average({1.0, 2.0}, 0), std::vector<double>{});
        EXPECT_NEAR_VECTOR(sliding_window_average({1.0, 2.0}, 3), std::vector<double>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
