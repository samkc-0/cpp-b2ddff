#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::stopwatch_exercise {

// Concept: Represent an object's mode with member state.
// Practice: Start, stop, reset, and advance elapsed time only while running.
// Watch for: tick should do nothing when the stopwatch is stopped.
//
// Task: Implement a deterministic Stopwatch class.
Stopwatch::Stopwatch() : elapsed_seconds_(0), running_(false) {
}

void Stopwatch::start() { running_ = true; }
void Stopwatch::stop() { running_ = false; }
void Stopwatch::reset() { elapsed_seconds_ = 0; }

void Stopwatch::tick(int seconds) {
    if (seconds < 0) {
        throw std::logic_error("tick amount must not be negative");
    }
    if (running_) {
        elapsed_seconds_ += seconds;
    }
}

int Stopwatch::elapsed_seconds() const { return elapsed_seconds_; }
bool Stopwatch::is_running() const { return running_; }

}  // namespace stage_03::classes::stopwatch_exercise
