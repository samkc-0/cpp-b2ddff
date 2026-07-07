#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::increment_all_exercise {

// Concept: A reference parameter lets a function update the caller's object.
// Practice: Mutate every element of a vector in place.
// Watch for: Returning a new vector would miss the point of this exercise.
//
// Task: Add 1 to every integer in values.
void increment_all(std::vector<int>& values) {
    for (auto& x : values)
        x++;
}

}  // namespace stage_01::references_const::increment_all_exercise
