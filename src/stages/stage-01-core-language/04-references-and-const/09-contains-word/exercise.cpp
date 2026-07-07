#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::contains_word_exercise {

// Concept: Use const references and string_view for efficient read-only lookup.
// Practice: Compare a std::string from the vector with a std::string_view
// target without modifying either.
// Watch for: This should be an exact, case-sensitive match.
//
// Task: Return true when words contains a string equal to target.
bool contains_word(const std::vector<std::string>& words, std::string_view target) {
    for (auto& w : words) {
        if (w == target)
            return true;

    }
    return false;
}

}  // namespace stage_01::references_const::contains_word_exercise
