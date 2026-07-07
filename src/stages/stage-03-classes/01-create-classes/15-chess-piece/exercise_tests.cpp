#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

namespace {
int failures = 0;
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) { if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; } }
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
}  // namespace

int main() {
    using namespace stage_03::classes::chess_piece_exercise;
    try {
        const ChessPiece queen{Color::White, PieceType::Queen, 5, 4};
        EXPECT_EQUAL(queen.color(), Color::White);
        EXPECT_EQUAL(queen.type(), PieceType::Queen);
        EXPECT_EQUAL(queen.algebraic_position(), std::string("e4"));
        EXPECT_TRUE(queen.is_white());
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
