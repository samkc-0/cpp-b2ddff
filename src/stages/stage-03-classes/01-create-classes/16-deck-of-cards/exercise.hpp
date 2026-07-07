#pragma once

#include <optional>
#include <string>
#include <vector>

namespace stage_03::classes::deck_of_cards_exercise {

class Card {
public:
    Card(std::string rank, std::string suit);

    const std::string& rank() const;
    const std::string& suit() const;
    std::string to_string() const;

    bool operator==(const Card& other) const;

private:
    std::string rank_;
    std::string suit_;
};

class Deck {
public:
    Deck();

    std::size_t size() const;
    bool is_empty() const;
    void add_card(const Card& card);
    std::optional<Card> draw();

private:
    std::vector<Card> cards_;
};

}  // namespace stage_03::classes::deck_of_cards_exercise
