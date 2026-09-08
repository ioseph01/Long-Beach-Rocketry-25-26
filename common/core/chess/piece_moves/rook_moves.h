#pragma once
#include "chess_globals.h"

namespace LBR
{
namespace Chess
{
class ChessBoard;

/**
 * @brief Gets the raw probably possible movement bitboard for the Rook
 * 
 * @param square the bitboard of the specific queen instance
 * @param occupied the bitboard of all pieces
 * @param rank_mask the bitboard for movement on the current rank
 * @param file_mask the bitboard for movement on the current file
 * 
 * @return A bitboard of possible destinations for the rook
 */
uint64_t get_rook_attacks(uint64_t square, uint64_t occupied,
                          uint64_t rank_mask, uint64_t file_mask);

/**
 * @brief Extracts pseudo-legal rook moves onto the encoded move stack
 * 
 * @param board A reference to the Chess board
 * @param color The color of the rook [-1, +1]
 * @return The number of rook moves that were added to the encoded move stack
 */
uint8_t rook_moves(ChessBoard& board, int8_t color);

}  // namespace Chess
}  // namespace LBR