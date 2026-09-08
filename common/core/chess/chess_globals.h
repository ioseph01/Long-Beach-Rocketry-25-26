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
constexpr std::array<uint64_t, 64> KING_ATTACKS = calculate_king_moves();
constexpr std::array<uint64_t, 64> KNIGHT_ATTACKS = calculate_knight_moves();
constexpr std::array<uint64_t, 64> DIAG_ATTACKS = calculate_bishop_diags();
constexpr std::array<uint64_t, 64> ANTI_DIAG_ATTACKS =
    calculate_bishop_anti_diags();

extern Stack<uint32_t, 128> encoded_moves_stack;
extern Stack<uint32_t, 128> move_options;
extern std::array<Pair<uint32_t>, MAX_DEPTH> KILLER_MOVES;
extern Stack<uint64_t, 256> history_stack;
extern Stack<uint8_t, 64> extracted_offsets_stack;

uint16_t PIECE_TO_VAL(uint8_t piece);
uint16_t PROMOTION_VAL(uint8_t piece);

uint64_t get_current_rank(uint64_t square);
uint64_t get_current_file(uint64_t square);
uint64_t reverse_bits(uint64_t bits);
uint64_t get_ray_attacks(uint64_t square, uint64_t occupied, uint64_t mask);

uint32_t encode_move(uint8_t color, uint8_t piece, uint8_t start_offset,
                     uint8_t captured_piece, uint8_t end_offset,
                     uint8_t misc_flags);
ChessMove decode_move(uint32_t move);

uint32_t encode_log_entry(uint32_t move, bool w_king_castle,
                          bool w_queen_castle, bool b_king_castle,
                          bool b_queen_castle);

ChessEntry decode_log_entry(uint32_t encoded_entry);

uint8_t extract_offsets(uint64_t bitboard);

uint16_t evaluate_move(uint32_t encoded_move, uint16_t mat, int8_t depth = -1);

void move_to_uci(uint32_t move, char* out);
uint8_t uci_to_offset(char* in);
void offset_to_uci(uint8_t offset, char* out);

constexpr std::array<uint64_t, 64> calculate_king_moves(void);

constexpr std::array<uint64_t, 64> calculate_knight_moves(void);

constexpr std::array<uint64_t, 64> calculate_bishop_diags(void);

constexpr std::array<uint64_t, 64> calculate_bishop_anti_diags(void);

}  // namespace Chess
}  // namespace LBR