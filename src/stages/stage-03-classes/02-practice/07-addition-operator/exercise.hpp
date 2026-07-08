#pragma once

namespace stage_03::practice::addition_operator_exercise {

class Distance {
public:
    explicit Distance(int meters);

    int meters() const;
    Distance operator+(const Distance& other) const;
    bool operator==(const Distance& other) const;

private:
    int meters_;
};

}  // namespace stage_03::practice::addition_operator_exercise
