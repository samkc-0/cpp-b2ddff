#include "exercise.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>

namespace stage_03::practice::stream_output_operator_exercise {

// Concept: operator<< lets a class define stream formatting.
// Practice: Implement a non-member output operator using const access.
// Watch for: Return the stream so output operations can chain.
//
// Task: Format NameTag as "First Last".
NameTag::NameTag(std::string first, std::string last) : first_(std::move(first)), last_(std::move(last)) {
    throw std::logic_error("TODO: implement NameTag constructor");
}

const std::string& NameTag::first() const { throw std::logic_error("TODO: implement first"); }
const std::string& NameTag::last() const { throw std::logic_error("TODO: implement last"); }

std::ostream& operator<<(std::ostream& stream, const NameTag& tag) {
    (void)tag;
    throw std::logic_error("TODO: implement operator<<");
}

}  // namespace stage_03::practice::stream_output_operator_exercise
