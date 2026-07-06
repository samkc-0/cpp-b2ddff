#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::parse_integer_exercise {

// Task: Parse text as a base-10 integer.
// Return std::nullopt when text is empty or contains non-integer characters.
std::optional<int> parse_integer(std::string_view text) {
    (void)text;
    throw std::logic_error("TODO: implement parse_integer");
}

}  // namespace stage_01::std_optional::parse_integer_exercise
