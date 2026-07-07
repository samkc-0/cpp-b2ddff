#include "exercise.hpp"
#include <algorithm>
#include <stdexcept>

namespace stage_01::std_optional::find_maximum_exercise {

// Task: Return the largest integer in values.
// Return std::nullopt when values is empty.
std::optional<int> find_maximum(const std::vector<int>& values) {
    if (values.empty())
        return std::nullopt;
    auto it = std::max_element(values.begin(), values.end());
    return *it;
}

}  // namespace stage_01::std_optional::find_maximum_exercise
