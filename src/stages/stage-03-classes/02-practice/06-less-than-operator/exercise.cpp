#include "exercise.hpp"

#include <stdexcept>
#include <utility>

namespace stage_03::practice::less_than_operator_exercise {

// Concept: operator< defines sort order for a class.
// Practice: Compare priority first, then title as a tie-breaker.
// Watch for: The comparison should be strict and consistent.
//
// Task: Implement Task ordering by lower priority number first.
Task::Task(std::string title, int priority) : title_(std::move(title)), priority_(priority) {
    throw std::logic_error("TODO: implement Task constructor");
}

const std::string& Task::title() const { throw std::logic_error("TODO: implement title"); }
int Task::priority() const { throw std::logic_error("TODO: implement priority"); }
bool Task::operator<(const Task& other) const { (void)other; throw std::logic_error("TODO: implement operator<"); }

}  // namespace stage_03::practice::less_than_operator_exercise
