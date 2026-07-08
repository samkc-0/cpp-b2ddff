#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::library_exercise {

// Concept: A class can manage a collection and provide search behavior.
// Practice: Mutate through add_book and query through const methods.
// Watch for: find_by_prefix should return the first matching title.
//
// Task: Implement a small Library of book titles.
void Library::add_book(std::string title) { titles_.push_back(title); }
bool Library::contains(std::string_view title) const {
    auto it = std::find(titles_.begin(), titles_.end(), title);
    return it != titles_.end();
}
std::optional<std::string> Library::find_by_prefix(std::string_view prefix) const {
    auto it = std::find_if(
            titles_.begin(), titles_.end(),
            [&prefix](const std::string& title){
                return title.starts_with(prefix);
            });
    if (it != titles_.end()) return *it;
    return std::nullopt;
}

std::size_t Library::size() const { return titles_.size(); }

}  // namespace stage_03::classes::library_exercise
