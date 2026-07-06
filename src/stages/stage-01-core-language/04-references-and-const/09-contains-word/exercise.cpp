#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::contains_word_exercise {

// Task: Return true when words contains a string equal to target.
// Avoid copying words or target.
bool contains_word(const std::vector<std::string>& words, std::string_view target) {
    (void)words;
    (void)target;
    throw std::logic_error("TODO: implement contains_word");
}

}  // namespace stage_01::references_const::contains_word_exercise
