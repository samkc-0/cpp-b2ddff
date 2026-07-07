#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::find_first_occurrence_exercise {

// Task: Return the index of the first occurrence of target in values.
// Return std::nullopt when target is not present.
std::optional<std::size_t> find_first_occurrence(const std::vector<int>& values, int target) {
    auto it = std::find(values.begin(), values.end(), target);
    if (it == values.end())
        return std::nullopt;
    return it - values.begin();
}

}  // namespace stage_01::std_optional::find_first_occurrence_exercise
