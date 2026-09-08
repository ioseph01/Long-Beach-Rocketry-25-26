#pragma once

#include "chess_globals.h"

namespace LBR
{
namespace Chess
{

class ChessBoard;
uint64_t KING_ATTACKS[64];

void calculate_king_moves(uint64_t* ret);
uint64_t king_destinations(ChessBoard& board, int8_t color, int8_t offset);
uint8_t king_moves(ChessBoard& board, int8_t color, int8_t offset);
uint8_t in_check(ChessBoard& board, int8_t enemy_color);
}  // namespace Chess
}  // namespace LBR