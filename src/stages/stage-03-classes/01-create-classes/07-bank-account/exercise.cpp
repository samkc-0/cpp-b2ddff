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
    throw std::logic_error("TODO: implement BankAccount constructor");
}

const std::string& BankAccount::owner() const { throw std::logic_error("TODO: implement owner"); }
int BankAccount::balance_cents() const { throw std::logic_error("TODO: implement balance_cents"); }
void BankAccount::deposit(int amount_cents) { (void)amount_cents; throw std::logic_error("TODO: implement deposit"); }
bool BankAccount::withdraw(int amount_cents) { (void)amount_cents; throw std::logic_error("TODO: implement withdraw"); }

}  // namespace stage_03::classes::bank_account_exercise
