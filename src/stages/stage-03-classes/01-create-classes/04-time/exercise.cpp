#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::time_exercise {

// Concept: Keep object state valid through constructor validation.
// Practice: Store hour/minute/second and expose read-only const methods.
// Watch for: Valid time ranges are 0-23, 0-59, and 0-59.
//
// Task: Implement a Time class with HH:MM:SS formatting.
Time::Time(int hour, int minute, int second) : hour_(hour), minute_(minute), second_(second) {
    throw std::logic_error("TODO: implement Time constructor");
}

int Time::hour() const { throw std::logic_error("TODO: implement hour"); }
int Time::minute() const { throw std::logic_error("TODO: implement minute"); }
int Time::second() const { throw std::logic_error("TODO: implement second"); }
int Time::seconds_since_midnight() const { throw std::logic_error("TODO: implement seconds_since_midnight"); }
std::string Time::to_string() const { throw std::logic_error("TODO: implement to_string"); }

}  // namespace stage_03::classes::time_exercise
