#include "exercise.hpp"

#include <stdexcept>
#include <iomanip>
#include <sstream>

namespace stage_03::classes::date_exercise {

// Concept: Use constructors to validate and initialize a simple value object.
// Practice: Implement accessors, string formatting, equality, and ordering.
// Watch for: Months should be 1-12 and days should be valid for the month.
//
// Task: Implement a Date class with ISO formatting as YYYY-MM-DD.
Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {
    if (month_ < 1 || month_ > 12)
        throw std::logic_error("bad month");
    size_t max_days;
    switch (month_) {
        case  2:
            max_days = is_leap_year() ? 29 : 28;
            break;
        case  4:
        case  6:
        case  9:
        case 11:
            max_days = 30;
            break;
        default:
            max_days = 31;
    }
    if (day_ < 1 || day_ > max_days)
        throw std::logic_error("bad day");

}

int Date::year() const { return year_; }
int Date::month() const { return month_; }
int Date::day() const { return day_; }
std::string Date::to_iso_string() const {
    std::ostringstream oss;
    oss << year_ << '-'
        << std::setfill('0') << std::setw(2) << month_ << '-'
        << std::setw(2) << day_;
    return oss.str();
}
bool Date::operator==(const Date& other) const {
    return year_ == other.year()
        && month_ == other.month()
        && day_ == other.day();
}
bool Date::operator<(const Date& other) const {
    if (year_ < other.year())
        return true;
    if (year_ == other.year() && month_ < other.month())
        return true;
    if (year_ == other.year() && month_ == other.month() && day_ < other.day())
        return true;
    return false;
}
bool Date::is_leap_year() const {
    return (year_ % 400 == 0 || (year_ % 4 == 0 && year_ % 100 != 0));
}

}  // namespace stage_03::classes::date_exercise
