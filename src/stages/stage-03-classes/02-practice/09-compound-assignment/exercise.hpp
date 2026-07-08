#pragma once

namespace stage_03::practice::compound_assignment_exercise {

class Counter {
public:
    explicit Counter(int value = 0);

    int value() const;
    Counter& operator+=(int amount);
    bool operator==(const Counter& other) const;

private:
    int value_;
};

}  // namespace stage_03::practice::compound_assignment_exercise
