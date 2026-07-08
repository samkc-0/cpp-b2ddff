#include "exercise.hpp"

#include <stdexcept>
#include <utility>

namespace stage_03::classes::student_exercise {

// Concept: Classes can own a collection and compute derived information.
// Practice: Store a name, add grades, and expose const query methods.
// Watch for: The average of no grades should be 0.0.
//
// Task: Implement Student with grade tracking.
Student::Student(std::string name) : name_(std::move(name)) {
    grades_ = std::vector<int>();
}

const std::string& Student::name() const { return name_; }
void Student::add_grade(int grade) { grades_.push_back(grade); }
double Student::average_grade() const {
    if (grades_.empty())
        return 0.0;
    double s = 0;
    for (auto g : grades_)
        s += g;
    return s / grades_.size();
}
bool Student::has_passing_average() const { return average_grade() > 50; }

}  // namespace stage_03::classes::student_exercise
