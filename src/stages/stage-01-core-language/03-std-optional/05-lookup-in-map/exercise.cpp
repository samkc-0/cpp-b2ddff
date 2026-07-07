#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::lookup_in_map_exercise {

// Task: Return the integer associated with key in values.
// Return std::nullopt when key does not exist.
std::optional<int> lookup_in_map(const std::map<std::string, int>& values, std::string_view key) {
    auto result = values.find(std::string(key));
    if (result == values.end())
        return std::nullopt;
    return result->second;
}

}  // namespace stage_01::std_optional::lookup_in_map_exercise
