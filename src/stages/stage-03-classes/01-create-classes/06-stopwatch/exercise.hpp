#pragma once

namespace stage_03::classes::stopwatch_exercise {

class Stopwatch {
public:
    Stopwatch();

    void start();
    void stop();
    void reset();
    void tick(int seconds);
    int elapsed_seconds() const;
    bool is_running() const;

private:
    int elapsed_seconds_;
    bool running_;
};

}  // namespace stage_03::classes::stopwatch_exercise
