#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::stopwatch_exercise {

// Concept: Represent an object's mode with member state.
// Practice: Start, stop, reset, and advance elapsed time only while running.
// Watch for: tick should do nothing when the stopwatch is stopped.
//
// Task: Implement a deterministic Stopwatch class.
Stopwatch::Stopwatch() : elapsed_seconds_(0), running_(false) {
    throw std::logic_error("TODO: implement Stopwatch constructor");
}

void Stopwatch::start() { throw std::logic_error("TODO: implement start"); }
void Stopwatch::stop() { throw std::logic_error("TODO: implement stop"); }
void Stopwatch::reset() { throw std::logic_error("TODO: implement reset"); }
void Stopwatch::tick(int seconds) { (void)seconds; throw std::logic_error("TODO: implement tick"); }
int Stopwatch::elapsed_seconds() const { throw std::logic_error("TODO: implement elapsed_seconds"); }
bool Stopwatch::is_running() const { throw std::logic_error("TODO: implement is_running"); }

}  // namespace stage_03::classes::stopwatch_exercise
