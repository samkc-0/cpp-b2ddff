#include "exercise.hpp"

#include <stdexcept>
#include <utility>

namespace stage_03::classes::bank_account_exercise {

// Concept: Encapsulate data and protect class invariants.
// Practice: Validate money operations and expose read-only accessors.
// Watch for: Withdrawals should fail without changing balance when funds are
// insufficient.
//
// Task: Implement a simple BankAccount measured in cents.
BankAccount::BankAccount(std::string owner, int balance_cents)
    : owner_(std::move(owner)), balance_cents_(balance_cents) {
}

const std::string& BankAccount::owner() const { return owner_; }
int BankAccount::balance_cents() const { return balance_cents_; }
void BankAccount::deposit(int amount_cents) { balance_cents_ += amount_cents; }
bool BankAccount::withdraw(int amount_cents) {
    if (amount_cents <= balance_cents_) {
        balance_cents_ -= amount_cents;
        return true;
    }
    return false;
}

}  // namespace stage_03::classes::bank_account_exercise
