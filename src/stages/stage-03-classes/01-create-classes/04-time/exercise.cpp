#include "exercise.hpp"

#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace stage_03::classes::time_exercise {

// Concept: Keep object state valid through constructor validation.
// Practice: Store hour/minute/second and expose read-only const methods.
// Watch for: Valid time ranges are 0-23, 0-59, and 0-59.
//
// Task: Implement a Time class with HH:MM:SS formatting.
Time::Time(int hour, int minute, int second) : hour_(hour), minute_(minute), second_(second) {
    if (hour < 0 || hour > 23) {
        throw std::logic_error("hour must be between 0 and 23");
    }
    if (minute < 0 || minute > 59) {
        throw std::logic_error("minute must be between 0 and 59");
    }
    if (second < 0 || second > 59) {
        throw std::logic_error("second must be between 0 and 59");
    }
}

int Time::hour() const { return hour_; }
int Time::minute() const { return minute_; }
int Time::second() const { return second_; }

int Time::seconds_since_midnight() const {
    return hour_ * 60 * 60 + minute_ * 60 + second_;
}

std::string Time::to_string() const {
    std::ostringstream output;
    output << std::setfill('0')
           << std::setw(2) << hour_ << ':'
           << std::setw(2) << minute_ << ':'
           << std::setw(2) << second_;
    return output.str();
}

}  // namespace stage_03::classes::time_exercise
