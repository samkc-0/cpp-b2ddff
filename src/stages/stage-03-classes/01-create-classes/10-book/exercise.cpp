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
}

const std::string& Book::title() const { return title_; }
const std::string& Book::author() const { return author_; }
int Book::publication_year() const { return publication_year_; }
bool Book::is_classic(int current_year) const { return current_year - publication_year_ >= 50; }
bool Book::operator==(const Book& other) const {
    return title_ == other.title()
        && author_ == other.author()
        && publication_year_ == other.publication_year();
}
}  // namespace stage_03::classes::book_exercise
