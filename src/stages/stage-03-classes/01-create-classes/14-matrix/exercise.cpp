#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::matrix_exercise {

// Concept: Represent a small fixed-size data structure inside a class.
// Practice: Implement indexed access, a computed property, and operators.
// Watch for: at(row, column) should reject indexes outside 0 or 1.
//
// Task: Implement a 2x2 integer matrix.
Matrix2x2::Matrix2x2(int a00, int a01, int a10, int a11) : values_{{a00, a01}, {a10, a11}} {
    throw std::logic_error("TODO: implement Matrix2x2 constructor");
}

int Matrix2x2::at(int row, int column) const { (void)row; (void)column; throw std::logic_error("TODO: implement at"); }
int Matrix2x2::determinant() const { throw std::logic_error("TODO: implement determinant"); }
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& other) const { (void)other; throw std::logic_error("TODO: implement operator+"); }
bool Matrix2x2::operator==(const Matrix2x2& other) const { (void)other; throw std::logic_error("TODO: implement operator=="); }

}  // namespace stage_03::classes::matrix_exercise
