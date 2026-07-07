#include "exercise.hpp"

#include <stdexcept>
#include <string>

namespace stage_01::std_optional::parse_integer_exercise {

// Task: Parse text as a base-10 integer.
// Return std::nullopt when text is empty or contains non-integer characters.
std::optional<int> parse_integer(std::string_view text) {

    if (text.find_first_not_of("-0123456789") != std::string::npos)
        return std::nullopt;

    auto pos = text.find('-');
    if (pos != std::string_view::npos && pos != 0)
        return std::nullopt;

    if (text.empty())
        return std::nullopt;

    return std::stoi(std::string(text));
}

}  // namespace stage_01::std_optional::parse_integer_exercise
