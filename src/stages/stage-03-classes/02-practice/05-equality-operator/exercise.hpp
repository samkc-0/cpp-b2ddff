#pragma once

namespace stage_03::practice::equality_operator_exercise {

class Point {
public:
    Point(int x, int y);

    int x() const;
    int y() const;
    bool operator==(const Point& other) const;

private:
    int x_;
    int y_;
};

}  // namespace stage_03::practice::equality_operator_exercise
