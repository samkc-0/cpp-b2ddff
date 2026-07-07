#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::find_key_by_value_exercise {

// Task: Return the first key whose mapped value equals target.
// Return std::nullopt when no mapped value matches target.
std::optional<std::string> find_key_by_value(const std::map<std::string, int>& values, int target) {
    for (const auto& [k, v] : values) {
        if (v == target) return k;
    }
    return std::nullopt;
}

}  // namespace stage_01::std_optional::find_key_by_value_exercise
