#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_string::palindrome_exercise {

// Task: Return true when text reads the same forward and backward.
// Ignore case and non-alphanumeric characters.
bool is_palindrome(std::string_view text) {
    for (size_t i = 0, j = text.length() - 1; i != j; ++i, --j)
        if (text[i] != text[j]) return false;
    return true;
}

}  // namespace stage_01::std_string::palindrome_exercise
