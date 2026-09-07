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

struct ChessMove
{
    uint8_t color;
    uint8_t piece;
    uint8_t start_offset;
    uint8_t captured_piece;
    uint8_t end_offset;
    uint8_t flags;
};

}  // namespace Chess
}  // namespace LBR