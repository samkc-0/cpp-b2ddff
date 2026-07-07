#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::wallet_exercise {

// Concept: Hide representation and expose a tiny safe API.
// Practice: Keep a balance non-negative through method behavior.
// Watch for: Failed spending should not change the wallet.
//
// Task: Implement a Wallet that stores a number of cents.
Wallet::Wallet() : cents_(0) {
    throw std::logic_error("TODO: implement Wallet constructor");
}

int Wallet::cents() const { throw std::logic_error("TODO: implement cents"); }
void Wallet::add_cents(int amount) { (void)amount; throw std::logic_error("TODO: implement add_cents"); }
bool Wallet::spend_cents(int amount) { (void)amount; throw std::logic_error("TODO: implement spend_cents"); }
bool Wallet::is_empty() const { throw std::logic_error("TODO: implement is_empty"); }

}  // namespace stage_03::classes::wallet_exercise
