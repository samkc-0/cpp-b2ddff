#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::practice::member_functions_exercise {

// Concept: Member functions operate on one specific object instance.
// Practice: Read and mutate private state through methods.
// Watch for: Each method should update this object's temperature_.
//
// Task: Implement Thermostat member functions.
Thermostat::Thermostat(int temperature) : temperature_(temperature) {
    throw std::logic_error("TODO: implement Thermostat constructor");
}

int Thermostat::temperature() const { throw std::logic_error("TODO: implement temperature"); }
void Thermostat::warm_up() { throw std::logic_error("TODO: implement warm_up"); }
void Thermostat::cool_down() { throw std::logic_error("TODO: implement cool_down"); }
void Thermostat::set_temperature(int temperature) { (void)temperature; throw std::logic_error("TODO: implement set_temperature"); }

}  // namespace stage_03::practice::member_functions_exercise
