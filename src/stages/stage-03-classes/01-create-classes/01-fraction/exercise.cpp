#include "exercise.hpp"

#include <stdexcept>
#include <numeric>

namespace stage_03::classes::fraction_exercise {

// Concept: Store class invariants and expose behavior through const methods.
// Practice: Normalize a fraction, reject a zero denominator, and overload
// equality/addition.
// Watch for: A negative denominator should be moved to the numerator.
//
// Task: Implement a Fraction class that stores reduced numerator/denominator.
Fraction::Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
    if (denominator == 0)
        throw std::logic_error("zero dvision!!");
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    int q = std::gcd(numerator, denominator);
    numerator_ = numerator / q;
    denominator_ = denominator / q;
}

int Fraction::numerator() const {
    return numerator_;
}

int Fraction::denominator() const {
    return denominator_;
}

Fraction Fraction::operator+(const Fraction& other) const {
    int d = denominator() * other.denominator();
    int a = numerator() * other.denominator();
    int b = other.numerator() * denominator();
    return Fraction(a + b, d);
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator_ == other.numerator() && denominator_ == other.denominator();
}

}  // namespace stage_03::classes::fraction_exercise
