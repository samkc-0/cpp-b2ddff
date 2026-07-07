#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <optional>
#include <string>

namespace {
int failures = 0;
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) { if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; } }
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
void expect_false(bool actual, int line) { if (actual) { ++failures; std::cerr << "Line " << line << ": expected false\n"; } }
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
#define EXPECT_FALSE(actual) expect_false((actual), __LINE__)
}  // namespace

int main() {
    using namespace stage_03::classes::deck_of_cards_exercise;
    try {
        const Card ace{"A", "Spades"};
        EXPECT_EQUAL(ace.to_string(), std::string("A of Spades"));
        Deck deck;
        EXPECT_TRUE(deck.is_empty());
        deck.add_card(ace);
        deck.add_card(Card{"K", "Hearts"});
        EXPECT_EQUAL(deck.size(), 2U);
        const auto drawn = deck.draw();
        EXPECT_TRUE(drawn.has_value());
        EXPECT_EQUAL(*drawn, (Card{"K", "Hearts"}));
        EXPECT_FALSE(deck.is_empty());
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
