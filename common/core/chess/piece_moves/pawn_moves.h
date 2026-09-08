#pragma once
#include "chess_globals.h"

namespace LBR
{
namespace Chess
{

class ChessBoard;

/**
* @brief Extracts pseudo-legal pawn moves onto the encoded move stack
* @param board A reference to the Chess board
* @param color The color of the pawns [-1, +1]
* @return The number of pawn moves that were added to the encoded move stack
*/
uint8_t pawn_moves(ChessBoard& board, int8_t color);

/**
* @brief Extracts pawn destinations, encodes the moves, and adds them to the 
* encoded move stack 
* @param board A reference to the Chess board
* @param color The color_flag of the pawns [WHITE_FLAG BLACK_FLAG]
* @param offset The destinations bitboard
* @param shift The offset to subtract by to get the starting offset

* @return The number of pawn moves that were added to the encoded move stack
*/
uint8_t process_pawn_moves(ChessBoard& board, uint8_t color,
                           uint64_t destinations, int8_t shift);

}  // namespace Chess
}  // namespace LBR