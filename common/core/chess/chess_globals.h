#pragma once
#include <cstdint>
#include "chess_constants.h"
#include "chess_move_struct.h"
#include "pair.h"
#include "stack.h"

namespace LBR
{
namespace Chess
{
/**
 * @brief Pre-calculated move options for pieces
 */

constexpr std::array<uint64_t, 64> KING_ATTACKS = calculate_king_moves();
constexpr std::array<uint64_t, 64> KNIGHT_ATTACKS = calculate_knight_moves();
constexpr std::array<uint64_t, 64> DIAG_ATTACKS = calculate_bishop_diags();
constexpr std::array<uint64_t, 64> ANTI_DIAG_ATTACKS =
    calculate_bishop_anti_diags();

/**
 * @brief Global stacks used throughout the library
 */

/**
  * @brief Contains encoded moves
  */
extern Stack<uint32_t, 196> encoded_moves_stack;

/**
 * @brief Contains encoded moves that are options for the player to select
 */
extern Stack<uint32_t, 64> move_options;

/**
 * @brief Contains quiet moves in that have high evaluation
 */
extern std::array<Pair<uint32_t>, MAX_DEPTH> KILLER_MOVES;

/**
 * @brief Contains the encoded move + castling rights
 */
extern Stack<uint32_t, 160> log_stack;

/**
 * @brief Contains the Zobrist hash for position storage and repetition detection
 */
extern Stack<uint64_t, 160> history_stack;

/**
 * @brief Contains temporary values that have been extracted from a bitboard
 * Mainly used to extract offsets and iterate over them
 */
extern Stack<uint8_t, 128> extracted_offsets_stack;

/**
 * @brief Gets the value given piece or promotion
 * 
 * @param piece
 * @return The piece's value
 */
uint16_t PIECE_TO_VAL(uint8_t piece);

/**
 * @brief Wrapper for promotion value getting function
 * Emphasizes Queen and Knight 
 */
uint16_t PROMOTION_VAL(uint8_t piece);

/**
 * @brief Gets the current rank given the bitboard
 */
uint64_t get_current_rank(uint64_t square);

/**
 * @brief Gets the current file given the bitboard
 */
uint64_t get_current_file(uint64_t square);

uint64_t reverse_bits(uint64_t bits);

/**
 * @brief Gets the positions that can be moved to given current square, occupied, 
 * and movement mask
 */
uint64_t get_ray_attacks(uint64_t square, uint64_t occupied, uint64_t mask);

/**
 * @brief Encodes move parameters into 23 bit
 * 
 * @param color WHITE_FLAG 0 or BLACK_FLAG 1
 * @param piece PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
 * @param start_offset Offset in [0,64)
 * @param captured_piece PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
 * @param end_offset Offset in [0,64)
 * @param misc_flags QUIET, PASSANT, DOUBLE_PUSH, CASTLE, PROMOTION
 * 
 * @return The encoded move as a uint32_t
 */
uint32_t encode_move(uint8_t color, uint8_t piece, uint8_t start_offset,
                     uint8_t captured_piece, uint8_t end_offset,
                     uint8_t misc_flags);

/**
 * @brief Decodes the 23 bit number into a ChessMove
 * 
 * @param move The 23-bit encoded move
 * @return A struct that contains color, piece, start_offset,
 *  captured_piece, end_offset, misc_flags
 */
ChessMove decode_move(uint32_t move);

uint32_t encode_log_entry(uint32_t move, bool w_king_castle,
                          bool w_queen_castle, bool b_king_castle,
                          bool b_queen_castle);

ChessEntry decode_log_entry(uint32_t encoded_entry);

/**
 * @brief Breaks a bitboard into offsets and adds it to the
 * extract_offsets STACK
 * @note Remember to pop all of the newly added values of the stack
 * during iteration
 * 
 * @param bitboard A 64-bit bitboard
 * @return The number of newly added values to the stack
 */
uint8_t extract_offsets(uint64_t bitboard);

/**
 * @brief Assigns a score to a move
 * 
 * @param encoded_move The encoded 23-bit move that will be unpacked
 * @param mat The current board material count used for
 * transitioning piece-square table score from middle to end game
 * @param depth Used to recall quiet moves 
 * 
 * @return The score of the move
 */
int16_t evaluate_move(uint32_t encoded_move, uint16_t mat, int8_t depth = -1);

/**
 * @brief Converts a move to a UCI string
 * 
 * @param move A 23-bit encoded move
 * @param out A char-string of length 5 that will be mutated
 */
void move_to_uci(uint32_t move, char* out);

/**
 * @brief Helper function that converts a UCI string to an offset
 * 
 * @param in A char-string of length 5 that will be analyzed
 * @return The offset in range [0, 64)
 */
uint8_t uci_to_offset(char* in);

/**
 * @brief Helper function that converts an offset to a UCI string
 * 
 * @param offset An uint in range [0, 64)
 * @param in A char-string of length 5 that will be mutated
 */
void offset_to_uci(uint8_t offset, char* out);

/**
 * @brief Pre-calculates pseudo-legal move options for certain pieces
 */

constexpr std::array<uint64_t, 64> calculate_king_moves(void);

constexpr std::array<uint64_t, 64> calculate_knight_moves(void);

constexpr std::array<uint64_t, 64> calculate_bishop_diags(void);

constexpr std::array<uint64_t, 64> calculate_bishop_anti_diags(void);

}  // namespace Chess
}  // namespace LBR