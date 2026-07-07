#include "exercise.hpp"

#include <stdexcept>
#include <utility>

namespace stage_03::classes::deck_of_cards_exercise {

// Concept: Compose classes by storing one class inside another.
// Practice: Implement Card as a value type and Deck as a container owner.
// Watch for: draw should remove and return the top card, or std::nullopt when
// the deck is empty.
//
// Task: Implement Card and Deck.
Card::Card(std::string rank, std::string suit) : rank_(std::move(rank)), suit_(std::move(suit)) {
    throw std::logic_error("TODO: implement Card constructor");
}

const std::string& Card::rank() const { throw std::logic_error("TODO: implement rank"); }
const std::string& Card::suit() const { throw std::logic_error("TODO: implement suit"); }
std::string Card::to_string() const { throw std::logic_error("TODO: implement to_string"); }
bool Card::operator==(const Card& other) const { (void)other; throw std::logic_error("TODO: implement Card operator=="); }

Deck::Deck() = default;
std::size_t Deck::size() const { throw std::logic_error("TODO: implement size"); }
bool Deck::is_empty() const { throw std::logic_error("TODO: implement is_empty"); }
void Deck::add_card(const Card& card) { (void)card; throw std::logic_error("TODO: implement add_card"); }
std::optional<Card> Deck::draw() { throw std::logic_error("TODO: implement draw"); }

}  // namespace stage_03::classes::deck_of_cards_exercise
