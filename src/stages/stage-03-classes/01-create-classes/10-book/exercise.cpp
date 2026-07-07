#include "exercise.hpp"

#include <stdexcept>
#include <utility>

namespace stage_03::classes::book_exercise {

// Concept: Store several related fields behind a stable interface.
// Practice: Use constructor initialization, const accessors, and equality.
// Watch for: is_classic should compare years, not hard-code today's date.
//
// Task: Implement Book; a book is classic if it is at least 50 years old.
Book::Book(std::string title, std::string author, int publication_year)
    : title_(std::move(title)), author_(std::move(author)), publication_year_(publication_year) {
    throw std::logic_error("TODO: implement Book constructor");
}

const std::string& Book::title() const { throw std::logic_error("TODO: implement title"); }
const std::string& Book::author() const { throw std::logic_error("TODO: implement author"); }
int Book::publication_year() const { throw std::logic_error("TODO: implement publication_year"); }
bool Book::is_classic(int current_year) const { (void)current_year; throw std::logic_error("TODO: implement is_classic"); }
bool Book::operator==(const Book& other) const { (void)other; throw std::logic_error("TODO: implement operator=="); }

}  // namespace stage_03::classes::book_exercise
