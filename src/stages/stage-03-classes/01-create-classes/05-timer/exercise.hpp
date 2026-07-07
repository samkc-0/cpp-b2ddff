#pragma once

namespace stage_03::classes::timer_exercise {

class Timer {
public:
    explicit Timer(int duration_seconds);

    int duration_seconds() const;
    int remaining_seconds() const;
    bool is_finished() const;
    void tick(int seconds);
    void reset();

private:
    int duration_seconds_;
    int remaining_seconds_;
};

}  // namespace stage_03::classes::timer_exercise
