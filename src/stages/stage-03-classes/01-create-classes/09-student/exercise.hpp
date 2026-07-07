#pragma once

#include <string>
#include <vector>

namespace stage_03::classes::student_exercise {

class Student {
public:
    explicit Student(std::string name);

    const std::string& name() const;
    void add_grade(int grade);
    double average_grade() const;
    bool has_passing_average() const;

private:
    std::string name_;
    std::vector<int> grades_;
};

}  // namespace stage_03::classes::student_exercise
