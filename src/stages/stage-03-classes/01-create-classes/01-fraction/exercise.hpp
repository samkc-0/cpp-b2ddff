#pragma once

namespace stage_03::classes::fraction_exercise {

class Fraction {
public:
    Fraction(int numerator, int denominator);

    int numerator() const;
    int denominator() const;

    Fraction operator+(const Fraction& other) const;
    bool operator==(const Fraction& other) const;

private:
    int numerator_;
    int denominator_;
};

}  // namespace stage_03::classes::fraction_exercise
