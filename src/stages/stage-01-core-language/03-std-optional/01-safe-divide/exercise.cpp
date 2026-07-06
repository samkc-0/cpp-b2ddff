#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::safe_divide_exercise {

// Task: Return numerator / denominator.
// Return std::nullopt when denominator is zero.
std::optional<double> safe_divide(double numerator, double denominator) {
    (void)numerator;
    (void)denominator;
    throw std::logic_error("TODO: implement safe_divide");
}

}  // namespace stage_01::std_optional::safe_divide_exercise
