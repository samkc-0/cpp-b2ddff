#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::timer_exercise {

// Concept: Encapsulate mutable state behind a small public interface.
// Practice: Use constructor initialization and methods that update state.
// Watch for: Remaining time should never become negative.
//
// Task: Implement a countdown Timer measured in seconds.
Timer::Timer(int duration_seconds) : duration_seconds_(duration_seconds), remaining_seconds_(duration_seconds) {
    throw std::logic_error("TODO: implement Timer constructor");
}

int Timer::duration_seconds() const { throw std::logic_error("TODO: implement duration_seconds"); }
int Timer::remaining_seconds() const { throw std::logic_error("TODO: implement remaining_seconds"); }
bool Timer::is_finished() const { throw std::logic_error("TODO: implement is_finished"); }
void Timer::tick(int seconds) { (void)seconds; throw std::logic_error("TODO: implement tick"); }
void Timer::reset() { throw std::logic_error("TODO: implement reset"); }

}  // namespace stage_03::classes::timer_exercise
