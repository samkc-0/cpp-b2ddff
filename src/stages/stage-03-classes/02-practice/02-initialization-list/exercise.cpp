#include "exercise.hpp"

#include <stdexcept>
#include <utility>

namespace stage_03::practice::initialization_list_exercise {

// Concept: Constructor initialization lists are required for const members.
// Practice: Initialize const data members before the constructor body runs.
// Watch for: Assigning to const members in the body will not compile.
//
// Task: Implement UserProfile using an initialization list.
UserProfile::UserProfile(std::string username, int reputation)
    : username_(std::move(username)), reputation_(reputation) {
    throw std::logic_error("TODO: implement UserProfile constructor");
}

const std::string& UserProfile::username() const {
    throw std::logic_error("TODO: implement username");
}

int UserProfile::reputation() const {
    throw std::logic_error("TODO: implement reputation");
}

}  // namespace stage_03::practice::initialization_list_exercise
