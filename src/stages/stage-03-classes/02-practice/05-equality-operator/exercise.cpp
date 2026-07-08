#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::practice::equality_operator_exercise {

// Concept: operator== defines value equality for a class.
// Practice: Compare all member fields that define object identity.
// Watch for: Comparing only x or only y is incomplete.
//
// Task: Implement Point and operator==.
Point::Point(int x, int y) : x_(x), y_(y) {
    throw std::logic_error("TODO: implement Point constructor");
}

int Point::x() const { throw std::logic_error("TODO: implement x"); }
int Point::y() const { throw std::logic_error("TODO: implement y"); }
bool Point::operator==(const Point& other) const { (void)other; throw std::logic_error("TODO: implement operator=="); }

}  // namespace stage_03::practice::equality_operator_exercise
