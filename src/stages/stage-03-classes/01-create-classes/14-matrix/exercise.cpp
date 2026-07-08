#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::matrix_exercise {

// Concept: Represent a small fixed-size data structure inside a class.
// Practice: Implement indexed access, a computed property, and operators.
// Watch for: at(row, column) should reject indexes outside 0 or 1.
//
// Task: Implement a 2x2 integer matrix.
Matrix2x2::Matrix2x2(int a00, int a01, int a10, int a11) : values_{{a00, a01}, {a10, a11}} {
}

int Matrix2x2::at(int row, int column) const {
    if (row < 0 || row >= 2 || column < 0 || column >= 2)
        throw std::logic_error("index error");
    return values_[row][column];
}
int Matrix2x2::determinant() const {
    return values_[0][0] * values_[1][1] - values_[0][1] * values_[1][0];
}
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& other) const {
   int a = at(0, 0) + other.at(0, 0);
   int b = at(0, 1) + other.at(0, 1);
   int c = at(1, 0) + other.at(1, 0);
   int d = at(1, 1) + other.at(1, 1);
   return Matrix2x2(a, b, c, d);
}
bool Matrix2x2::operator==(const Matrix2x2& other) const {
   return at(0, 0) == other.at(0, 0)
       && at(0, 1) == other.at(0, 1)
       && at(1, 0) == other.at(1, 0)
       && at(1, 1) == other.at(1, 1);
}

}  // namespace stage_03::classes::matrix_exercise
