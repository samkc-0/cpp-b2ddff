#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::wallet_exercise {

// Concept: Hide representation and expose a tiny safe API.
// Practice: Keep a balance non-negative through method behavior.
// Watch for: Failed spending should not change the wallet.
//
// Task: Implement a Wallet that stores a number of cents.
Wallet::Wallet() : cents_(0) {
}

int Wallet::cents() const { return cents_; }
void Wallet::add_cents(int amount) { cents_ += amount; }
bool Wallet::spend_cents(int amount) {
    if (amount <= cents_) {
        cents_ -= amount;
        return true;
    }
    return false;
}
bool Wallet::is_empty() const { return cents_ == 0; }

}  // namespace stage_03::classes::wallet_exercise
