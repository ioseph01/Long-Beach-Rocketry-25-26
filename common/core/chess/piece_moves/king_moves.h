#pragma once

#include "chess_globals.h"

namespace LBR
{
namespace Chess
{

class ChessBoard;
/**
 * @brief Gets the raw probably possible movement bitboard for the King
 * 
 * @param board A reference to the Chess board
 * @param color The color of the king [-1, +1]
 * @param offset The offset of the king
 * 
 * @return A bitboard of possible destinations for the king
 */
uint64_t king_destinations(ChessBoard& board, int8_t color, uint8_t offset);

/**
 * @brief Extracts pseudo-legal king moves onto the encoded move stack
 * 
 * @param board A reference to the Chess board
 * @param color The color of the king [-1, +1]
 * @param offset The offset of the king
 * 
 * @return The number of king moves that were added to the encoded move stack
 */
uint8_t king_moves(ChessBoard& board, int8_t color, uint8_t offset);

/**
 * @brief Checks if a side is in check
 * @param board A reference to the Chess board
 * @param enemy_color The enemy color [-1, +1]
 * 
 * @return The number of attackers
 */
uint8_t in_check(ChessBoard& board, int8_t enemy_color);
}  // namespace Chess
}  // namespace LBR