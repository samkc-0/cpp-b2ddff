#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::date_exercise {

// Concept: Use constructors to validate and initialize a simple value object.
// Practice: Implement accessors, string formatting, equality, and ordering.
// Watch for: Months should be 1-12 and days should be valid for the month.
//
// Task: Implement a Date class with ISO formatting as YYYY-MM-DD.
Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {
    throw std::logic_error("TODO: implement Date constructor");
}

int Date::year() const { throw std::logic_error("TODO: implement year"); }
int Date::month() const { throw std::logic_error("TODO: implement month"); }
int Date::day() const { throw std::logic_error("TODO: implement day"); }
std::string Date::to_iso_string() const { throw std::logic_error("TODO: implement to_iso_string"); }
bool Date::operator==(const Date& other) const { (void)other; throw std::logic_error("TODO: implement operator=="); }
bool Date::operator<(const Date& other) const { (void)other; throw std::logic_error("TODO: implement operator<"); }

}  // namespace stage_03::classes::date_exercise
