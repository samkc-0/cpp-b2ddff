#include "exercise.hpp"

#include <stdexcept>
#include <utility>

namespace stage_03::practice::const_methods_exercise {

// Concept: const methods promise not to mutate the object.
// Practice: Mark read-only accessors const while leaving mutators non-const.
// Watch for: The tests call read-only methods through a const Label.
//
// Task: Implement Label with const query methods and a non-const clear method.
Label::Label(std::string text) : text_(std::move(text)) {
    throw std::logic_error("TODO: implement Label constructor");
}

const std::string& Label::text() const { throw std::logic_error("TODO: implement text"); }
std::size_t Label::length() const { throw std::logic_error("TODO: implement length"); }
bool Label::is_empty() const { throw std::logic_error("TODO: implement is_empty"); }
void Label::clear() { throw std::logic_error("TODO: implement clear"); }

}  // namespace stage_03::practice::const_methods_exercise
