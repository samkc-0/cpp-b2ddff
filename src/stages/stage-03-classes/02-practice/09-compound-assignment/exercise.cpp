#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::practice::compound_assignment_exercise {

// Concept: Compound assignment mutates the left-hand object and returns it.
// Practice: Implement operator+= and return *this.
// Watch for: Returning by value prevents chaining from working naturally.
//
// Task: Implement Counter with +=.
Counter::Counter(int value) : value_(value) {
    throw std::logic_error("TODO: implement Counter constructor");
}

int Counter::value() const { throw std::logic_error("TODO: implement value"); }
Counter& Counter::operator+=(int amount) { (void)amount; throw std::logic_error("TODO: implement operator+="); }
bool Counter::operator==(const Counter& other) const { (void)other; throw std::logic_error("TODO: implement operator=="); }

}  // namespace stage_03::practice::compound_assignment_exercise
