#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::circle_exercise {

// Concept: Encapsulate a single value and expose derived const methods.
// Practice: Validate construction and compute circle measurements.
// Watch for: Use pi consistently; tests allow a small floating-point tolerance.
//
// Task: Implement Circle.
Circle::Circle(double radius) : radius_(radius) {
    throw std::logic_error("TODO: implement Circle constructor");
}

double Circle::radius() const { throw std::logic_error("TODO: implement radius"); }
double Circle::diameter() const { throw std::logic_error("TODO: implement diameter"); }
double Circle::circumference() const { throw std::logic_error("TODO: implement circumference"); }
double Circle::area() const { throw std::logic_error("TODO: implement area"); }

}  // namespace stage_03::classes::circle_exercise
