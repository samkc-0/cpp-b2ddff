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
    throw std::logic_error("TODO: implement Student constructor");
}

const std::string& Student::name() const { throw std::logic_error("TODO: implement name"); }
void Student::add_grade(int grade) { (void)grade; throw std::logic_error("TODO: implement add_grade"); }
double Student::average_grade() const { throw std::logic_error("TODO: implement average_grade"); }
bool Student::has_passing_average() const { throw std::logic_error("TODO: implement has_passing_average"); }

}  // namespace stage_03::classes::student_exercise
