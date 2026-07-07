#pragma once

#include <string>

namespace stage_03::classes::chess_piece_exercise {

enum class Color { White, Black };
enum class PieceType { King, Queen, Rook, Bishop, Knight, Pawn };

class ChessPiece {
public:
    ChessPiece(Color color, PieceType type, int file, int rank);

    Color color() const;
    PieceType type() const;
    int file() const;
    int rank() const;
    std::string algebraic_position() const;
    bool is_white() const;

private:
    Color color_;
    PieceType type_;
    int file_;
    int rank_;
};

}  // namespace stage_03::classes::chess_piece_exercise
