#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::timer_exercise {

// Concept: Encapsulate mutable state behind a small public interface.
// Practice: Use constructor initialization and methods that update state.
// Watch for: Remaining time should never become negative.
//
// Task: Implement a countdown Timer measured in seconds.
Timer::Timer(int duration_seconds) : duration_seconds_(duration_seconds), remaining_seconds_(duration_seconds) {
    if (duration_seconds < 0) {
        throw std::logic_error("duration must not be negative");
    }
}

int Timer::duration_seconds() const { return duration_seconds_; }
int Timer::remaining_seconds() const { return remaining_seconds_; }
bool Timer::is_finished() const { return remaining_seconds_ == 0; }

void Timer::tick(int seconds) {
    if (seconds < 0) {
        throw std::logic_error("tick amount must not be negative");
    }

    if (seconds >= remaining_seconds_) {
        remaining_seconds_ = 0;
    } else {
        remaining_seconds_ -= seconds;
    }
}

void Timer::reset() { remaining_seconds_ = duration_seconds_; }

}  // namespace stage_03::classes::timer_exercise
