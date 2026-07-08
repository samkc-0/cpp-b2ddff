#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::practice::default_constructor_exercise {

// Concept: Default constructors create a useful initial object state.
// Practice: Initialize members so an object is immediately safe to use.
// Watch for: Built-in members like int are not automatically zeroed.
//
// Task: Implement Score so a default score starts at 0 points.
Score::Score() : points_(0) {
    throw std::logic_error("TODO: implement Score constructor");
}

int Score::points() const {
    throw std::logic_error("TODO: implement points");
}

void Score::add_points(int amount) {
    (void)amount;
    throw std::logic_error("TODO: implement add_points");
}

}  // namespace stage_03::practice::default_constructor_exercise
