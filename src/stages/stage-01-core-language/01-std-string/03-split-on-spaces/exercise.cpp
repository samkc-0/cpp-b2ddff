#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_string::split_on_spaces_exercise {

// Task: Split text into words separated by spaces.
// Ignore leading, trailing, and repeated spaces.
std::vector<std::string> split_on_spaces(std::string_view text) {

    std::vector<std::string> words;

    size_t i = 0;
    while (i < text.size()) {
        while (i < text.size() && text[i] == ' ')
            ++i;
        size_t start = i;
        while (i < text.size() && text[i] != ' ')
            ++i;
        if (start != i)
            words.emplace_back(text.substr(start, i - start));
    }
    return words;
}

}  // namespace stage_01::std_string::split_on_spaces_exercise
