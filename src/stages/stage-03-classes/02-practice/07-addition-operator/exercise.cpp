#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::practice::addition_operator_exercise {

// Concept: operator+ should return a new value rather than mutate operands.
// Practice: Implement addition for a small value type.
// Watch for: Keep both input Distance objects unchanged.
//
// Task: Implement Distance addition.
Distance::Distance(int meters) : meters_(meters) {
    throw std::logic_error("TODO: implement Distance constructor");
}

int Distance::meters() const { throw std::logic_error("TODO: implement meters"); }
Distance Distance::operator+(const Distance& other) const { (void)other; throw std::logic_error("TODO: implement operator+"); }
bool Distance::operator==(const Distance& other) const { (void)other; throw std::logic_error("TODO: implement operator=="); }

}  // namespace stage_03::practice::addition_operator_exercise
