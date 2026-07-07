#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::complex_number_exercise {

// Concept: Model a small mathematical value type with const operations.
// Practice: Store two fields, expose accessors, and implement operators.
// Watch for: Methods like magnitude and operator+ should not mutate the object.
//
// Task: Implement ComplexNumber with real/imaginary parts and addition.
ComplexNumber::ComplexNumber(double real, double imaginary) : real_(real), imaginary_(imaginary) {
    throw std::logic_error("TODO: implement ComplexNumber constructor");
}

double ComplexNumber::real() const {
    throw std::logic_error("TODO: implement real");
}

double ComplexNumber::imaginary() const {
    throw std::logic_error("TODO: implement imaginary");
}

double ComplexNumber::magnitude() const {
    throw std::logic_error("TODO: implement magnitude");
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    (void)other;
    throw std::logic_error("TODO: implement operator+");
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    (void)other;
    throw std::logic_error("TODO: implement operator==");
}

}  // namespace stage_03::classes::complex_number_exercise
