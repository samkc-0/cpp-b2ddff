#include "exercise.hpp"

#include <stdexcept>
#include <string>

namespace stage_01::std_optional::parse_double_exercise {

// Task: Parse text as a double.
// Return std::nullopt when text is empty or contains invalid characters.
std::optional<double> parse_double(std::string_view text) {
    if (text.empty())
        return std::nullopt;
    if (std::any_of(text.begin(), text.end(), [](unsigned char c){
            return std::isspace(c);
        })) {
        return std::nullopt;
    }

    try {
        std::size_t pos = 0;
        double value = std::stod(std::string(text), &pos);
        if (pos != text.size())
            return std::nullopt;
        return value;
    } catch (const std::invalid_argument&) {
        return std::nullopt;
    } catch (const std::out_of_range&) {
        return std::nullopt;
    }
}

}  // namespace stage_01::std_optional::parse_double_exercise
