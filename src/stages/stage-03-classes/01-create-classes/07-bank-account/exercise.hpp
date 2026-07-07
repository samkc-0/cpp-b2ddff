#pragma once

#include <string>

namespace stage_03::classes::bank_account_exercise {

class BankAccount {
public:
    BankAccount(std::string owner, int balance_cents);

    const std::string& owner() const;
    int balance_cents() const;
    void deposit(int amount_cents);
    bool withdraw(int amount_cents);

private:
    std::string owner_;
    int balance_cents_;
};

}  // namespace stage_03::classes::bank_account_exercise
