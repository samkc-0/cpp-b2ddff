#pragma once

#include <string>

namespace stage_03::classes::date_exercise {

class Date {
public:
    Date(int year, int month, int day);

    int year() const;
    int month() const;
    int day() const;
    std::string to_iso_string() const;

    bool operator==(const Date& other) const;
    bool operator<(const Date& other) const;

private:
    int year_;
    int month_;
    int day_;

    bool is_leap_year() const;
};

}  // namespace stage_03::classes::date_exercise
