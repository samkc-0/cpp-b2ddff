#include "exercise.hpp"

#include <stdexcept>
#include <numbers>

namespace stage_03::classes::circle_exercise {

// Concept: Encapsulate a single value and expose derived const methods.
// Practice: Validate construction and compute circle measurements.
// Watch for: Use pi consistently; tests allow a small floating-point tolerance.
//
// Task: Implement Circle.
Circle::Circle(double radius) : radius_(radius) {
}

double Circle::radius() const { return radius_; }
double Circle::diameter() const { return 2 * radius_; }
double Circle::circumference() const { return std::numbers::pi * diameter(); }
double Circle::area() const { return std::numbers::pi * radius_ * radius_; }

}  // namespace stage_03::classes::circle_exercise
