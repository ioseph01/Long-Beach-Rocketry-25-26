#pragma once
#include <cstdint>
#include "chess_globals.h"

namespace LBR
{

namespace Chess
{

class ChessBoard
{
public:
    uint64_t white_pieces() const;
    uint64_t black_pieces() const;

    void simulate(uint64_t encoded_move);
    void undo();
    int8_t get_piece_at_pos(uint64_t pos) const;

    int16_t evaluate() const;

private:
    /**
    * @brief Piece bitboards
    */
    uint64_t w_pawns{RANK2};
    uint64_t b_pawns{RANK7};
    uint64_t w_knights{B1 | G1};
    uint64_t b_knights{B8 | G8};
    uint64_t w_bishops{C1 | F1};
    uint64_t b_bishops{C8 | F8};
    uint64_t w_rooks{A1 | H1};
    uint64_t b_rooks{A8 | H8};
    uint64_t w_queens{D1};
    uint64_t b_queens{D8};
    uint64_t w_king{E1};
    uint64_t b_king{E8};
};
}  // namespace Chess
}  // namespace LBR