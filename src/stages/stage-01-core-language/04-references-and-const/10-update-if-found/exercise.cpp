#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::update_if_found_exercise {

// Concept: References are useful for controlled mutation of containers.
// Practice: Mutate a std::map through a non-const reference only when a key
// already exists.
// Watch for: Missing keys should not be inserted.
//
// Task: If key exists in values, update its mapped value and return true.
// If key does not exist, leave values unchanged and return false.
bool update_if_found(std::map<std::string, int>& values, std::string_view key, int new_value) {
    const std::string k(key);
    auto it = values.find(k);
    if (it != values.end()) {
        it->second = new_value;
        return true;
    }
    return false;
}

}  // namespace stage_01::references_const::update_if_found_exercise
