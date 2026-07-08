#include "exercise.hpp"

#include <stdexcept>
#include <cmath>

namespace stage_03::classes::complex_number_exercise {

// Concept: Model a small mathematical value type with const operations.
// Practice: Store two fields, expose accessors, and implement operators.
// Watch for: Methods like magnitude and operator+ should not mutate the object.
//
// Task: Implement ComplexNumber with real/imaginary parts and addition.
ComplexNumber::ComplexNumber(double real, double imaginary) : real_(real), imaginary_(imaginary) {
    real_ = real;
    imaginary_ = imaginary;
}

double ComplexNumber::real() const {
    return real_;
}

double ComplexNumber::imaginary() const {
    return imaginary_;
}

double ComplexNumber::magnitude() const {
    double y = real_ * real_ + imaginary_ * imaginary_;
    return std::sqrt(y);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    (void)other;
    double r = real_ + other.real();
    double i = imaginary_ + other.imaginary();
    return ComplexNumber(r, i);
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return real_ == other.real() && imaginary_ == other.imaginary();
}

}  // namespace stage_03::classes::complex_number_exercise
