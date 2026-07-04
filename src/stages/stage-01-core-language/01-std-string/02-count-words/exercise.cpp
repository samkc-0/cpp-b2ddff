#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_string::count_words_exercise {

// Task: Return the number of words in text.
// Words are separated by one or more whitespace characters.
std::size_t count_words(std::string_view text) {
    bool is_space = 1;
    size_t count = 0;
    for (char c : text) {
        bool start = is_space;
        if (c == ' ' || c == '\t')
            is_space = 1;
        else
            is_space = 0;
        if (start == 1 && is_space == 0)
            count += 1;
    }
    return count;
}

}  // namespace stage_01::std_string::count_words_exercise
