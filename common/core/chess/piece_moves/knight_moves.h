#pragma once

#include "chess_globals.h"

namespace LBR
{
namespace Chess
{

class ChessBoard;

uint64_t knight_destinations(ChessBoard& board, int8_t color, uint8_t offset);
uint8_t knight_moves(ChessBoard& board, int8_t color, uint8_t offset);
}  // namespace Chess
}  // namespace LBR