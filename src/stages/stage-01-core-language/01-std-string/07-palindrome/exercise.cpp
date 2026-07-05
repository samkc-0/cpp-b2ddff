#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_string::palindrome_exercise {

// Task: Return true when text reads the same forward and backward.
// Ignore case and non-alphanumeric characters.
bool is_palindrome(std::string_view text) {
    if (text.empty()) return true;
    if (text.length() == 1) return true;

    auto is_ascii = [](unsigned char c){
        return c <= 127;
    };

    size_t left = 0;
    size_t right = text.length() - 1;

    while (left < right) {
        while (left < right &&
                !std::isalnum(static_cast<unsigned char>(text[left])))
            ++left;
        while (left < right &&
                !std::isalnum(static_cast<unsigned char>(text[right])))
            --right;
        if (std::tolower(text[left]) != std::tolower(text[right]))
            return false;
        ++left;
        --right;
    }

    return true;

    return true;
}

}  // namespace stage_01::std_string::palindrome_exercise
