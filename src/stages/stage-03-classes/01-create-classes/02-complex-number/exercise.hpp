#pragma once

namespace stage_03::classes::complex_number_exercise {

class ComplexNumber {
public:
    ComplexNumber(double real, double imaginary);

    double real() const;
    double imaginary() const;
    double magnitude() const;

    ComplexNumber operator+(const ComplexNumber& other) const;
    bool operator==(const ComplexNumber& other) const;

private:
    double real_;
    double imaginary_;
};

}  // namespace stage_03::classes::complex_number_exercise
