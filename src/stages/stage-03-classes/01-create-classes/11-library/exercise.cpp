#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::library_exercise {

// Concept: A class can manage a collection and provide search behavior.
// Practice: Mutate through add_book and query through const methods.
// Watch for: find_by_prefix should return the first matching title.
//
// Task: Implement a small Library of book titles.
void Library::add_book(std::string title) { (void)title; throw std::logic_error("TODO: implement add_book"); }
bool Library::contains(std::string_view title) const { (void)title; throw std::logic_error("TODO: implement contains"); }
std::optional<std::string> Library::find_by_prefix(std::string_view prefix) const { (void)prefix; throw std::logic_error("TODO: implement find_by_prefix"); }
std::size_t Library::size() const { throw std::logic_error("TODO: implement size"); }

}  // namespace stage_03::classes::library_exercise
