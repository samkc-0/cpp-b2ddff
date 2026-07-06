#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::lookup_in_map_exercise {

// Task: Return the integer associated with key in values.
// Return std::nullopt when key does not exist.
std::optional<int> lookup_in_map(const std::map<std::string, int>& values, std::string_view key) {
    (void)values;
    (void)key;
    throw std::logic_error("TODO: implement lookup_in_map");
}

}  // namespace stage_01::std_optional::lookup_in_map_exercise
