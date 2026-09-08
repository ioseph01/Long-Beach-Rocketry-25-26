#pragma once
#include "chess_globals.h"

namespace LBR
{
namespace Chess
{

class ChessBoard;

uint8_t pawn_moves(ChessBoard& board, int8_t color);

uint8_t process_pawn_moves(ChessBoard& board, uint8_t color,
                           uint64_t destinations, int8_t shift);

}  // namespace Chess
}  // namespace LBR