#pragma once
#include "chess_globals.h"

namespace LBR
{
namespace Chess
{
class ChessBoard;

uint64_t get_bishop_attacks(uint64_t square, uint64_t occupied,
                            uint64_t diag_mask, uint64_t anti_diag_mask);

uint8_t bishop_moves(ChessBoard& board, int8_t color);

}  // namespace Chess

}  // namespace LBR
