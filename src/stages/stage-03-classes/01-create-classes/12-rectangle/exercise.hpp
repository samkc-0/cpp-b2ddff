#pragma once

namespace stage_03::classes::rectangle_exercise {

class Rectangle {
public:
    Rectangle(double width, double height);

    double width() const;
    double height() const;
    double area() const;
    double perimeter() const;
    bool is_square() const;

private:
    double width_;
    double height_;
};

}  // namespace stage_03::classes::rectangle_exercise
