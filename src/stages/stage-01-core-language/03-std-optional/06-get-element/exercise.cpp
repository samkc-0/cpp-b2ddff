#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::get_element_exercise {

// Task: Return values[index].
// Return std::nullopt when index is outside the vector.
std::optional<int> get_element(const std::vector<int>& values, std::size_t index) {
    if (index < 0 || index >= values.size())
        return std::nullopt;
    return values[index];
}

}  // namespace stage_01::std_optional::get_element_exercise
