#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::total_length_exercise {

// Concept: Use const references for read-only access to large objects.
// Practice: Iterate over a const std::vector<std::string>& without copying it.
// Watch for: The function should not mutate words or copy the whole vector.
//
// Task: Return the total number of characters across all words.
std::size_t total_length(const std::vector<std::string>& words) {
    size_t len = 0;
    for (const std::string& w : words) {
        len += w.size();
    }
    return len;

}

}  // namespace stage_01::references_const::total_length_exercise
