#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_string::trim_whitespace_exercise {

// Task: Return text with leading and trailing whitespace removed.
// Whitespace includes spaces, tabs, and newlines.
std::string trim_whitespace(std::string_view text) {
    std::string copy(text);
    auto is_not_space = [](unsigned char c) {
        return !std::isspace(c);
    };
    copy.erase(copy.begin(), std::find_if(copy.begin(), copy.end(), is_not_space));

    auto finale = std::find_if(copy.rbegin(), copy.rend(), is_not_space);
    copy.erase(finale.base(), copy.end());
    return copy;

}  // namespace stage_01::std_string::trim_whitespace_exercise

}
