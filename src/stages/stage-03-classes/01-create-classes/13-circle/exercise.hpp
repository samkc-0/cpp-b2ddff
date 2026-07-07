#pragma once

namespace stage_03::classes::circle_exercise {

class Circle {
public:
    explicit Circle(double radius);

    double radius() const;
    double diameter() const;
    double circumference() const;
    double area() const;

private:
    double radius_;
};

}  // namespace stage_03::classes::circle_exercise
