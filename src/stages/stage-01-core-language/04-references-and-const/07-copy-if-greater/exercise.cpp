#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::copy_if_greater_exercise {

// Concept: Mix const and non-const references to express intent.
// Practice: Read from source without modifying it, and append results to
// destination.
// Watch for: Do not clear destination; append to what the caller already has.
//
// Task: Append values from source that are greater than threshold to destination.
void copy_if_greater(const std::vector<int>& source, std::vector<int>& destination, int threshold) {
    for (auto& x : source) {
        if (x > threshold)
            destination.push_back(x);
    }
}

}  // namespace stage_01::references_const::copy_if_greater_exercise
