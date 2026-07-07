#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::references_const::longest_string_exercise {

// Concept: Return a lightweight view into data owned by the caller.
// Practice: Use const references for input and std::string_view for a
// non-owning result.
// Watch for: Do not return a view to a local temporary string.
//
// Task: Return a view of the longest string in words.
// Return std::nullopt when words is empty.
std::optional<std::string_view> longest_string(const std::vector<std::string>& words) {
    if (words.empty())
        return std::nullopt;
    size_t longest = 0;
    std::string_view out;
    for (const auto& w : words)
        if (w.size() > longest) {
            longest = w.size();
            out = std::string_view(w);
        }
    return out;
}

}  // namespace stage_01::references_const::longest_string_exercise
