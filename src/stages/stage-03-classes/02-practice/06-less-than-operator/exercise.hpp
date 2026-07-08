#pragma once

#include <string>

namespace stage_03::practice::less_than_operator_exercise {

class Task {
public:
    Task(std::string title, int priority);

    const std::string& title() const;
    int priority() const;
    bool operator<(const Task& other) const;

private:
    std::string title_;
    int priority_;
};

}  // namespace stage_03::practice::less_than_operator_exercise
