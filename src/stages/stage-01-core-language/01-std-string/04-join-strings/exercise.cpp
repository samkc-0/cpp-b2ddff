#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_string::join_strings_exercise {

// Task: Join all strings in parts with separator between adjacent strings.
// Return an empty string when parts is empty.
std::string join_strings(const std::vector<std::string>& parts, std::string_view separator) {
    std::string out;
    for (auto it = parts.begin(); it != parts.end(); ++it) {
        if (it != parts.begin())
            out += separator;
        out += *it;
    }
    return out;
}

}  // namespace stage_01::std_string::join_strings_exercise
