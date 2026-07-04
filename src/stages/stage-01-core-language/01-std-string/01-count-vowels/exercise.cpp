#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_string::count_vowels_exercise {

// Task: Return the number of vowels in text.
// Count both uppercase and lowercase A, E, I, O, and U.
bool is_vowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

std::size_t count_vowels(std::string_view text) {
    size_t vowels = 0;
    for (char c : text) {
        if (is_vowel(c))
            vowels++;
    }
    return vowels;
}

}  // namespace stage_01::std_string::count_vowels_exercise
