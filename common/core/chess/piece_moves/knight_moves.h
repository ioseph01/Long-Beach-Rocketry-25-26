#pragma once

#include "chess_globals.h"

namespace LBR
{
namespace Chess
{

class ChessBoard;
/**
 * @brief Returns the possible knight destinations for a knight at some offset
* @param board A reference to the Chess board
* @param color The color of the knight [-1, +1]
* @param offset The offset of the knight
*/
uint64_t knight_destinations(ChessBoard& board, int8_t color, uint8_t offset);

/**
* @brief Extracts pseudo-legal knight moves onto the encoded move stack
* @param board A reference to the Chess board
* @param color The color of the king [-1, +1]
* @param offset The offset of the king
* @return The number of knight moves that were added to the encoded move stack
*/
uint8_t knight_moves(ChessBoard& board, int8_t color, uint8_t offset);
}  // namespace Chess
}  // namespace LBR