#pragma once
#include "chess_globals.h"

namespace LBR
{
namespace Chess
{
class ChessBoard;

/**
 * @brief Gets the raw probably possible movement bitboard for the Bishop
 * 
 * @param square the bitboard of the specific queen instance
 * @param occupied the bitboard of all pieces
 * @param diag_mask the bitboard for movement on the current diagonal
 * @param anti_diag_mask the bitboard for movement on the current anti-diagonal
 * 
 * @return A bitboard of possible destinations for the bishop
 */
uint64_t get_bishop_attacks(uint64_t square, uint64_t occupied,
                            uint64_t diag_mask, uint64_t anti_diag_mask);

/**
 * @brief Extracts pseudo-legal bishop moves onto the encoded move stack
 * 
 * @param board A reference to the Chess board
 * @param color The color of the bishop [-1, +1]
 * @return The number of bishop moves that were added to the encoded move stack
 */
uint8_t bishop_moves(ChessBoard& board, int8_t color);

}  // namespace Chess

}  // namespace LBR
