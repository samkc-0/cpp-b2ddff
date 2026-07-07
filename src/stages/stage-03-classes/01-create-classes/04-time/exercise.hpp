#pragma once

#include <string>

namespace stage_03::classes::time_exercise {

class Time {
public:
    Time(int hour, int minute, int second);

    int hour() const;
    int minute() const;
    int second() const;
    int seconds_since_midnight() const;
    std::string to_string() const;

private:
    int hour_;
    int minute_;
    int second_;
};

}  // namespace stage_03::classes::time_exercise
