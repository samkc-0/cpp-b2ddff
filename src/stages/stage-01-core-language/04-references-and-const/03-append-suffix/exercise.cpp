#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::append_suffix_exercise {

// Concept: Use non-const references when a function is meant to mutate input.
// Practice: Modify each string in a std::vector<std::string>& in place.
// Watch for: suffix is read-only, so it should not be copied or modified.
//
// Task: Append suffix to every string in words.
void append_suffix(std::vector<std::string>& words, std::string_view suffix) {
    for (auto& w : words)
        w += suffix;
}

}  // namespace stage_01::references_const::append_suffix_exercise
