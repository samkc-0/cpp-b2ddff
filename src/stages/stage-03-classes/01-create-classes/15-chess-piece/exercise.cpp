#include "exercise.hpp"

#include <stdexcept>

namespace stage_03::classes::chess_piece_exercise {

// Concept: Use enums to model a small closed set of states.
// Practice: Store enum fields and position data behind const accessors.
// Watch for: file and rank should be in the board range 1 through 8.
//
// Task: Implement ChessPiece with algebraic position like "e4".
ChessPiece::ChessPiece(Color color, PieceType type, int file, int rank)
    : color_(color), type_(type), file_(file), rank_(rank) {
    throw std::logic_error("TODO: implement ChessPiece constructor");
}

Color ChessPiece::color() const { throw std::logic_error("TODO: implement color"); }
PieceType ChessPiece::type() const { throw std::logic_error("TODO: implement type"); }
int ChessPiece::file() const { throw std::logic_error("TODO: implement file"); }
int ChessPiece::rank() const { throw std::logic_error("TODO: implement rank"); }
std::string ChessPiece::algebraic_position() const { throw std::logic_error("TODO: implement algebraic_position"); }
bool ChessPiece::is_white() const { throw std::logic_error("TODO: implement is_white"); }

}  // namespace stage_03::classes::chess_piece_exercise
