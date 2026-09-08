#pragma once
#include "chess_globals.h"

namespace LBR
{
namespace Chess
{
class ChessBoard;

uint64_t get_rook_attacks(uint64_t square, uint64_t occupied,
                          uint64_t rank_mask, uint64_t file_mask);

uint8_t rook_moves(ChessBoard& board, int8_t color);

}  // namespace Chess
}  // namespace LBR