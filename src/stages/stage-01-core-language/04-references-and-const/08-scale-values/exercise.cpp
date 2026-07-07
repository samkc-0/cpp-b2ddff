#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::scale_values_exercise {

// Concept: Const references can support pure functions that do not mutate input.
// Practice: Read values by const reference and return a new transformed vector.
// Watch for: The input vector must remain unchanged.
//
// Task: Return a new vector where each value is multiplied by factor.
std::vector<double> scale_values(const std::vector<double>& values, double factor) {
    std::vector<double> out(values);
    for (auto& x : out) {
        x *= factor;
    }
    return out;
}

}  // namespace stage_01::references_const::scale_values_exercise
