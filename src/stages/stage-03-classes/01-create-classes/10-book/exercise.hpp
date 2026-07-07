#pragma once

#include <string>

namespace stage_03::classes::book_exercise {

class Book {
public:
    Book(std::string title, std::string author, int publication_year);

    const std::string& title() const;
    const std::string& author() const;
    int publication_year() const;
    bool is_classic(int current_year) const;

    bool operator==(const Book& other) const;

private:
    std::string title_;
    std::string author_;
    int publication_year_;
};

}  // namespace stage_03::classes::book_exercise
