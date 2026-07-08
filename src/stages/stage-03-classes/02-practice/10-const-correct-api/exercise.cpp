#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::practice::const_correct_api_exercise {

// Concept: A const-correct API lets callers inspect const objects safely.
// Practice: Make read-only methods const and return const references when
// exposing owned data.
// Watch for: item_at should reject an out-of-range index.
//
// Task: Implement Inventory with a const-correct read API.
void Inventory::add_item(std::string item) {
    (void)item;
    throw std::logic_error("TODO: implement add_item");
}

std::size_t Inventory::size() const { throw std::logic_error("TODO: implement size"); }
bool Inventory::contains(const std::string& item) const { (void)item; throw std::logic_error("TODO: implement contains"); }
const std::string& Inventory::item_at(std::size_t index) const { (void)index; throw std::logic_error("TODO: implement item_at"); }

}  // namespace stage_03::practice::const_correct_api_exercise
