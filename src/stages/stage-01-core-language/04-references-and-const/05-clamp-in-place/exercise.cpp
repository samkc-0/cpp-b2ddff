#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::clamp_in_place_exercise {

// Concept: Separate mutable data from read-only scalar parameters.
// Practice: Mutate values through a non-const reference while reading bounds
// by value.
// Watch for: The operation is in-place; the caller's vector should change.
//
// Task: Clamp every value into the inclusive range [minimum, maximum].
// Values below minimum become minimum; values above maximum become maximum.
void clamp_in_place(std::vector<int>& values, int minimum, int maximum) {
    for (auto& v : values) {
        if (v > maximum) v = maximum;
        if (v < minimum) v = minimum;
    }
}

}  // namespace stage_01::references_const::clamp_in_place_exercise
