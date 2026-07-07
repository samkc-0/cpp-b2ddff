#pragma once

namespace stage_03::classes::matrix_exercise {

class Matrix2x2 {
public:
    Matrix2x2(int a00, int a01, int a10, int a11);

    int at(int row, int column) const;
    int determinant() const;
    Matrix2x2 operator+(const Matrix2x2& other) const;
    bool operator==(const Matrix2x2& other) const;

private:
    int values_[2][2];
};

}  // namespace stage_03::classes::matrix_exercise
