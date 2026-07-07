#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::fraction_exercise {

// Concept: Store class invariants and expose behavior through const methods.
// Practice: Normalize a fraction, reject a zero denominator, and overload
// equality/addition.
// Watch for: A negative denominator should be moved to the numerator.
//
// Task: Implement a Fraction class that stores reduced numerator/denominator.
Fraction::Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
    throw std::logic_error("TODO: implement Fraction constructor");
}

int Fraction::numerator() const {
    throw std::logic_error("TODO: implement numerator");
}

int Fraction::denominator() const {
    throw std::logic_error("TODO: implement denominator");
}

Fraction Fraction::operator+(const Fraction& other) const {
    (void)other;
    throw std::logic_error("TODO: implement operator+");
}

bool Fraction::operator==(const Fraction& other) const {
    (void)other;
    throw std::logic_error("TODO: implement operator==");
}

}  // namespace stage_03::classes::fraction_exercise
