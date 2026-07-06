#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::copy_if_greater_exercise {

// Task: Append values from source that are greater than threshold to destination.
// Read source by const reference and mutate destination by non-const reference.
void copy_if_greater(const std::vector<int>& source, std::vector<int>& destination, int threshold) {
    (void)source;
    (void)destination;
    (void)threshold;
    throw std::logic_error("TODO: implement copy_if_greater");
}

}  // namespace stage_01::references_const::copy_if_greater_exercise
