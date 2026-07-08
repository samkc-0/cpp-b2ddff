#include "exercise.hpp"

#include <stdexcept>
#include <cmath>

namespace stage_03::classes::rectangle_exercise {

// Concept: Use const methods for computed properties of immutable dimensions.
// Practice: Validate constructor inputs and calculate area/perimeter.
// Watch for: Width and height should not be negative.
//
// Task: Implement Rectangle.
Rectangle::Rectangle(double width, double height) : width_(width), height_(height) {
}

double Rectangle::width() const { return width_; }
double Rectangle::height() const { return height_; }
double Rectangle::area() const { return width_ * height_; }
double Rectangle::perimeter() const { return 2 * width_ + 2 * height_; }
bool Rectangle::is_square() const {
    const double eps = 1e-9;
    return std::abs(width_ - height_) < eps;
}

}  // namespace stage_03::classes::rectangle_exercise
