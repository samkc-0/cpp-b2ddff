#pragma once

namespace stage_03::practice::default_constructor_exercise {

class Score {
public:
    Score();

    int points() const;
    void add_points(int amount);

private:
    int points_;
};

}  // namespace stage_03::practice::default_constructor_exercise
