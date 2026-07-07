#pragma once

namespace stage_03::classes::wallet_exercise {

class Wallet {
public:
    Wallet();

    int cents() const;
    void add_cents(int amount);
    bool spend_cents(int amount);
    bool is_empty() const;

private:
    int cents_;
};

}  // namespace stage_03::classes::wallet_exercise
