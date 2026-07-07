#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::safe_divide_exercise {

// Task: Return numerator / denominator.
// Return std::nullopt when denominator is zero.
std::optional<double> safe_divide(double numerator, double denominator) {
    if (denominator == 0) return std::nullopt;
    return numerator / denominator;
}

}  // namespace stage_01::std_optional::safe_divide_exercise
