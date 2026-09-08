#pragma once
#include <cstdint>
#include "chess_globals.h"

namespace LBR
{

namespace Chess
{

class ChessManager;

class ChessBoard
{
public:
    ChessBoard(ChessManager& manager_);

    uint64_t white_pieces() const;
    uint64_t black_pieces() const;

    /**
     * @brief Simulates a move and adds it the log and history stack
     * @param encoded_move The encoded move that will be unpacked and
     * simulated
     */
    void simulate(uint64_t encoded_move);

    /**
     * @brief Undos the last move if possible
     */
    void undo();

    /**
     * @brief Gets the piece at a certain position
     * @param pos The square bitboard
     * @returns The piece * its sign (color)
     */
    int8_t get_piece_at_pos(uint64_t pos) const;

    /**
     * @brief Evaluates the current position based on material
     * 
     * @return The evaluation based on board material (+ for white, - for black)
     */
    int16_t evaluate() const;

    int8_t turn() const;

    /**
     * @brief Checks if a given square is attacked by some side
     * 
     * @param square The bitboard position of the attacked square to check
     * @param enemy_color The enemy's sign [-1, +1]
     * 
     * @return The number of attackers on the square
     */
    uint8_t is_attacked(uint64_t square, int8_t enemy_color) const;

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

    /**
     * @brief Castling rights for both sides
     */

    bool w_castle_kingside{true}, w_castle_queenside{true}, b_castle_kingside,
        b_castle_queenside{true};

    ChessManager& manager;
};
}  // namespace Chess
}  // namespace LBR