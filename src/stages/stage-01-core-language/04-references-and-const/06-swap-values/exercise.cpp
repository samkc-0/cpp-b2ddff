#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::swap_values_exercise {

// Concept: References can bind directly to caller variables.
// Practice: Use int& parameters so assignments affect the original variables.
// Watch for: Passing by value would only swap local copies.
//
// Task: Swap the two integers by modifying the referenced variables.
void swap_values(int& left, int& right) {
    int tmp = left;
    left = right;
    right = tmp;
}

}  // namespace stage_01::references_const::swap_values_exercise
