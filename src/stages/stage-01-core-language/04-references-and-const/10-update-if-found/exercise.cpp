#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::update_if_found_exercise {

// Task: If key exists in values, update its mapped value and return true.
// If key does not exist, leave values unchanged and return false.
bool update_if_found(std::map<std::string, int>& values, std::string_view key, int new_value) {
    (void)values;
    (void)key;
    (void)new_value;
    throw std::logic_error("TODO: implement update_if_found");
}

}  // namespace stage_01::references_const::update_if_found_exercise
