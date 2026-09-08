#pragma once
#include <cstdint>

namespace LBR
{
namespace Chess
{
constexpr uint8_t QUIET_FLAG = 0;
constexpr uint8_t PASSANT_FLAG = 1;
constexpr uint8_t CASTLE_KINGSIDE_FLAG = 2;
constexpr uint8_t CASTLE_QUEENSIDE_FLAG = 3;
constexpr uint8_t DOUBLE_PUSH_FLAG = 4;
constexpr uint8_t PROMOTE_KNIGHT_FLAG = 8;
constexpr uint8_t PROMOTE_BISHOP_FLAG = 9;
constexpr uint8_t PROMOTE_ROOK_FLAG = 10;
constexpr uint8_t PROMOTE_QUEEN_FLAG = 11;

/**
 * @brief Unpacked chess move
 * color[0]; WHITE_FLAG, BLACK_FLAG
 * piece[1:3]; KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN
 * start_offset[4:9]; [0, 64)
 * captured_piece[10:12]; KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN
 * end_offset[13:18]; [0, 64)
 * flags[19:22]; QUIET_FLAG, PASSANT_FLAG, CASTLE_, DOUBLE_PUSH, PROMOTE_
 */
struct ChessMove
{
    uint8_t color;
    uint8_t piece;
    uint8_t start_offset;
    uint8_t captured_piece;
    uint8_t end_offset;
    uint8_t flags;

    bool is_promotion() const
    {
        return (8 <= flags) && (flags <= 11);
    }
};

struct ChessEntry
{
    uint32_t encoded_move;
    bool w_king_castle;
    bool w_queen_castle;
    bool b_king_castle;
    bool b_queen_castle;
};

}  // namespace Chess
}  // namespace LBR