#include "exercise.hpp"

#include <stdexcept>
#include <regex>

namespace stage_01::std_string::replace_all_exercise {

// Task: Return a copy of text where every non-overlapping occurrence of from
// is replaced with to. If from is empty, return text unchanged.
std::string replace_all(std::string_view text, std::string_view from, std::string_view to) {
    if (from.empty()) return std::string(text);
    std::string out(text);
    size_t i = 0;
    while ((i = out.find(from, i)) != std::string::npos) {
        out.replace(i, from.size(), to);
        i += to.size();
    }
    return out;
}

}  // namespace stage_01::std_string::replace_all_exercise
