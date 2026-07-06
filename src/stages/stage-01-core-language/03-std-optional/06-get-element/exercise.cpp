#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::get_element_exercise {

// Task: Return values[index].
// Return std::nullopt when index is outside the vector.
std::optional<int> get_element(const std::vector<int>& values, std::size_t index) {
    (void)values;
    (void)index;
    throw std::logic_error("TODO: implement get_element");
}

}  // namespace stage_01::std_optional::get_element_exercise
