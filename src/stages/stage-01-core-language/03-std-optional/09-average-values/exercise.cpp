#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::average_values_exercise {

// Task: Return the arithmetic mean of values.
// Return std::nullopt when values is empty.
std::optional<double> average_values(const std::vector<double>& values) {
    if (values.empty()) return std::nullopt;
    double s = 0;
    for (auto x : values)
        s += x;
    return s / (double)values.size();
}

}  // namespace stage_01::std_optional::average_values_exercise
