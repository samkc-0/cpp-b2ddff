#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::rectangle_exercise {

// Concept: Use const methods for computed properties of immutable dimensions.
// Practice: Validate constructor inputs and calculate area/perimeter.
// Watch for: Width and height should not be negative.
//
// Task: Implement Rectangle.
Rectangle::Rectangle(double width, double height) : width_(width), height_(height) {
    throw std::logic_error("TODO: implement Rectangle constructor");
}

double Rectangle::width() const { throw std::logic_error("TODO: implement width"); }
double Rectangle::height() const { throw std::logic_error("TODO: implement height"); }
double Rectangle::area() const { throw std::logic_error("TODO: implement area"); }
double Rectangle::perimeter() const { throw std::logic_error("TODO: implement perimeter"); }
bool Rectangle::is_square() const { throw std::logic_error("TODO: implement is_square"); }

}  // namespace stage_03::classes::rectangle_exercise
