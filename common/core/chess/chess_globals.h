#pragma once
#include <cstdint>
#include "chess_move_struct.h"
#include "pair.h"
#include "stack.h"

namespace LBR
{
namespace Chess
{

constexpr uint64_t CLEAR_BITMASK = 0x0000000000000000;
constexpr uint64_t SET_BITMASK = 0xFFFFFFFFFFFFFFFF;

constexpr uint8_t A1_OFFSET = 0;
constexpr uint8_t B1_OFFSET = 1;
constexpr uint8_t C1_OFFSET = 2;
constexpr uint8_t D1_OFFSET = 3;
constexpr uint8_t E1_OFFSET = 4;
constexpr uint8_t F1_OFFSET = 5;
constexpr uint8_t G1_OFFSET = 6;
constexpr uint8_t H1_OFFSET = 7;
constexpr uint8_t A2_OFFSET = 8;
constexpr uint8_t B2_OFFSET = 9;
constexpr uint8_t C2_OFFSET = 10;
constexpr uint8_t D2_OFFSET = 11;
constexpr uint8_t E2_OFFSET = 12;
constexpr uint8_t F2_OFFSET = 13;
constexpr uint8_t G2_OFFSET = 14;
constexpr uint8_t H2_OFFSET = 15;
constexpr uint8_t A3_OFFSET = 16;
constexpr uint8_t B3_OFFSET = 17;
constexpr uint8_t C3_OFFSET = 18;
constexpr uint8_t D3_OFFSET = 19;
constexpr uint8_t E3_OFFSET = 20;
constexpr uint8_t F3_OFFSET = 21;
constexpr uint8_t G3_OFFSET = 22;
constexpr uint8_t H3_OFFSET = 23;
constexpr uint8_t A4_OFFSET = 24;
constexpr uint8_t B4_OFFSET = 25;
constexpr uint8_t C4_OFFSET = 26;
constexpr uint8_t D4_OFFSET = 27;
constexpr uint8_t E4_OFFSET = 28;
constexpr uint8_t F4_OFFSET = 29;
constexpr uint8_t G4_OFFSET = 30;
constexpr uint8_t H4_OFFSET = 31;
constexpr uint8_t A5_OFFSET = 32;
constexpr uint8_t B5_OFFSET = 33;
constexpr uint8_t C5_OFFSET = 34;
constexpr uint8_t D5_OFFSET = 35;
constexpr uint8_t E5_OFFSET = 36;
constexpr uint8_t F5_OFFSET = 37;
constexpr uint8_t G5_OFFSET = 38;
constexpr uint8_t H5_OFFSET = 39;
constexpr uint8_t A6_OFFSET = 40;
constexpr uint8_t B6_OFFSET = 41;
constexpr uint8_t C6_OFFSET = 42;
constexpr uint8_t D6_OFFSET = 43;
constexpr uint8_t E6_OFFSET = 44;
constexpr uint8_t F6_OFFSET = 45;
constexpr uint8_t G6_OFFSET = 46;
constexpr uint8_t H6_OFFSET = 47;
constexpr uint8_t A7_OFFSET = 48;
constexpr uint8_t B7_OFFSET = 49;
constexpr uint8_t C7_OFFSET = 50;
constexpr uint8_t D7_OFFSET = 51;
constexpr uint8_t E7_OFFSET = 52;
constexpr uint8_t F7_OFFSET = 53;
constexpr uint8_t G7_OFFSET = 54;
constexpr uint8_t H7_OFFSET = 55;
constexpr uint8_t A8_OFFSET = 56;
constexpr uint8_t B8_OFFSET = 57;
constexpr uint8_t C8_OFFSET = 58;
constexpr uint8_t D8_OFFSET = 59;
constexpr uint8_t E8_OFFSET = 60;
constexpr uint8_t F8_OFFSET = 61;
constexpr uint8_t G8_OFFSET = 62;
constexpr uint8_t H8_OFFSET = 63;

constexpr uint64_t A1 = 1ULL << A1_OFFSET;
constexpr uint64_t A2 = 1ULL << A2_OFFSET;
constexpr uint64_t A3 = 1ULL << A3_OFFSET;
constexpr uint64_t A4 = 1ULL << A4_OFFSET;
constexpr uint64_t A5 = 1ULL << A5_OFFSET;
constexpr uint64_t A6 = 1ULL << A6_OFFSET;
constexpr uint64_t A7 = 1ULL << A7_OFFSET;
constexpr uint64_t A8 = 1ULL << A8_OFFSET;
constexpr uint64_t B1 = 1ULL << B1_OFFSET;
constexpr uint64_t B2 = 1ULL << B2_OFFSET;
constexpr uint64_t B3 = 1ULL << B3_OFFSET;
constexpr uint64_t B4 = 1ULL << B4_OFFSET;
constexpr uint64_t B5 = 1ULL << B5_OFFSET;
constexpr uint64_t B6 = 1ULL << B6_OFFSET;
constexpr uint64_t B7 = 1ULL << B7_OFFSET;
constexpr uint64_t B8 = 1ULL << B8_OFFSET;
constexpr uint64_t C1 = 1ULL << C1_OFFSET;
constexpr uint64_t C2 = 1ULL << C2_OFFSET;
constexpr uint64_t C3 = 1ULL << C3_OFFSET;
constexpr uint64_t C4 = 1ULL << C4_OFFSET;
constexpr uint64_t C5 = 1ULL << C5_OFFSET;
constexpr uint64_t C6 = 1ULL << C6_OFFSET;
constexpr uint64_t C7 = 1ULL << C7_OFFSET;
constexpr uint64_t C8 = 1ULL << C8_OFFSET;
constexpr uint64_t D1 = 1ULL << D1_OFFSET;
constexpr uint64_t D2 = 1ULL << D2_OFFSET;
constexpr uint64_t D3 = 1ULL << D3_OFFSET;
constexpr uint64_t D4 = 1ULL << D4_OFFSET;
constexpr uint64_t D5 = 1ULL << D5_OFFSET;
constexpr uint64_t D6 = 1ULL << D6_OFFSET;
constexpr uint64_t D7 = 1ULL << D7_OFFSET;
constexpr uint64_t D8 = 1ULL << D8_OFFSET;
constexpr uint64_t E1 = 1ULL << E1_OFFSET;
constexpr uint64_t E2 = 1ULL << E2_OFFSET;
constexpr uint64_t E3 = 1ULL << E3_OFFSET;
constexpr uint64_t E4 = 1ULL << E4_OFFSET;
constexpr uint64_t E5 = 1ULL << E5_OFFSET;
constexpr uint64_t E6 = 1ULL << E6_OFFSET;
constexpr uint64_t E7 = 1ULL << E7_OFFSET;
constexpr uint64_t E8 = 1ULL << E8_OFFSET;
constexpr uint64_t F1 = 1ULL << F1_OFFSET;
constexpr uint64_t F2 = 1ULL << F2_OFFSET;
constexpr uint64_t F3 = 1ULL << F3_OFFSET;
constexpr uint64_t F4 = 1ULL << F4_OFFSET;
constexpr uint64_t F5 = 1ULL << F5_OFFSET;
constexpr uint64_t F6 = 1ULL << F6_OFFSET;
constexpr uint64_t F7 = 1ULL << F7_OFFSET;
constexpr uint64_t F8 = 1ULL << F8_OFFSET;
constexpr uint64_t G1 = 1ULL << G1_OFFSET;
constexpr uint64_t G2 = 1ULL << G2_OFFSET;
constexpr uint64_t G3 = 1ULL << G3_OFFSET;
constexpr uint64_t G4 = 1ULL << G4_OFFSET;
constexpr uint64_t G5 = 1ULL << G5_OFFSET;
constexpr uint64_t G6 = 1ULL << G6_OFFSET;
constexpr uint64_t G7 = 1ULL << G7_OFFSET;
constexpr uint64_t G8 = 1ULL << G8_OFFSET;
constexpr uint64_t H1 = 1ULL << H1_OFFSET;
constexpr uint64_t H2 = 1ULL << H2_OFFSET;
constexpr uint64_t H3 = 1ULL << H3_OFFSET;
constexpr uint64_t H4 = 1ULL << H4_OFFSET;
constexpr uint64_t H5 = 1ULL << H5_OFFSET;
constexpr uint64_t H6 = 1ULL << H6_OFFSET;
constexpr uint64_t H7 = 1ULL << H7_OFFSET;
constexpr uint64_t H8 = 1ULL << H8_OFFSET;

constexpr uint64_t A_FILE = A1 | A2 | A3 | A4 | A5 | A6 | A7 | A8;
constexpr uint64_t B_FILE = B1 | B2 | B3 | B4 | B5 | B6 | B7 | B8;
constexpr uint64_t C_FILE = C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8;
constexpr uint64_t D_FILE = D1 | D2 | D3 | D4 | D5 | D6 | D7 | D8;
constexpr uint64_t E_FILE = E1 | E2 | E3 | E4 | E5 | E6 | E7 | E8;
constexpr uint64_t F_FILE = F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8;
constexpr uint64_t G_FILE = G1 | G2 | G3 | G4 | G5 | G6 | G7 | G8;
constexpr uint64_t H_FILE = H1 | H2 | H3 | H4 | H5 | H6 | H7 | H8;

constexpr uint64_t RANK1 = A1 | B1 | C1 | D1 | E1 | F1 | G1 | H1;
constexpr uint64_t RANK2 = A2 | B2 | C2 | D2 | E2 | F2 | G2 | H2;
constexpr uint64_t RANK3 = A3 | B3 | C3 | D3 | E3 | F3 | G3 | H3;
constexpr uint64_t RANK4 = A4 | B4 | C4 | D4 | E4 | F4 | G4 | H4;
constexpr uint64_t RANK5 = A5 | B5 | C5 | D5 | E5 | F5 | G5 | H5;
constexpr uint64_t RANK6 = A6 | B6 | C6 | D6 | E6 | F6 | G6 | H6;
constexpr uint64_t RANK7 = A7 | B7 | C7 | D7 | E7 | F7 | G7 | H7;
constexpr uint64_t RANK8 = A8 | B8 | C8 | D8 | E8 | F8 | G8 | H8;

constexpr uint64_t W_KINGSIDE_PATH = F1 | G1;
constexpr uint64_t W_KINGSIDE_ROOK_POS = F1;
constexpr uint64_t W_KINGSIDE_KING_POS = G1;
constexpr uint64_t W_QUEENSIDE_PATH = D1 | C1 | B1;
constexpr uint64_t W_QUEENSIDE_ROOK_POS = D1;
constexpr uint64_t W_QUEENSIDE_KING_POS = C1;

constexpr uint64_t B_KINGSIDE_PATH = F8 | G8;
constexpr uint64_t B_KINGSIDE_ROOK_POS = F8;
constexpr uint64_t B_KINGSIDE_KING_POS = G8;
constexpr uint64_t B_QUEENSIDE_PATH = D8 | C8 | B8;
constexpr uint64_t B_QUEENSIDE_ROOK_POS = D8;
constexpr uint64_t B_QUEENSIDE_KING_POS = C8;

constexpr uint8_t PAWN = 1;
constexpr uint8_t KNIGHT = 2;
constexpr uint8_t BISHOP = 3;
constexpr uint8_t ROOK = 5;
constexpr uint8_t QUEEN = 6;
constexpr uint8_t KING = 7;

constexpr uint16_t PAWN_VALUE = 100;
constexpr uint16_t KNIGHT_VALUE = 310;
constexpr uint16_t BISHOP_VALUE = 320;
constexpr uint16_t ROOK_VALUE = 500;
constexpr uint16_t QUEEN_VALUE = 900;
constexpr uint16_t KING_VALUE = 0;

constexpr uint16_t CASTLE_VALUE = 200;
constexpr uint16_t CAPTURE_VALUE = 5000;
constexpr uint16_t CHECKMATE_VALUE = 20000;
constexpr uint16_t KILLER_VALUE_1 = 500;
constexpr uint16_t KILLER_VALUE_2 = 600;

constexpr int8_t ROOK_DIRECTIONS[] = {-8, -1, 1, 8};
constexpr int8_t BISHOP_DIRECTIONS[] = {-9, -7, 7, 9};

constexpr uint16_t TOTAL_NONPAWN_VALUE =
    2 * (PAWN_VALUE + KNIGHT_VALUE + BISHOP_VALUE + ROOK_VALUE + QUEEN_VALUE);

constexpr int8_t WHITE = 1;
constexpr int8_t BLACK = -1;

constexpr uint8_t WHITE_FLAG = 0;
constexpr uint8_t BLACK_FLAG = 1;

constexpr uint8_t MAX_DEPTH = 10;

Stack<uint32_t, 128> encoded_moves_stack;
std::array<Pair<uint32_t>, MAX_DEPTH> KILLER_MOVES;
Stack<uint64_t, 256> history_stack;
Stack<uint8_t, 64> extracted_offsets_stack;

uint16_t PIECE_TO_VAL(uint8_t piece);
uint16_t PROMOTION_VAL(uint8_t piece);

uint64_t get_current_rank(uint64_t square);
uint64_t get_current_file(uint64_t square);
uint64_t reverse_bits(uint64_t bits);
uint64_t get_ray_attacks(uint64_t bitboard, uint64_t occupied, uint64_t mask);

uint32_t encode_move(uint8_t color, uint8_t piece, uint8_t start_offset,
                     uint8_t captured_piece, uint8_t end_offset,
                     uint8_t misc_flags);
ChessMove decode_move(uint32_t move);

uint32_t encode_log_entry(uint32_t move, bool w_king_castle,
                          bool w_queen_castle, bool b_king_castle,
                          bool b_queen_castle);

ChessEntry decode_log_entry(uint32_t encoded_entry);

void extract_offsets(uint64_t bitboard);

uint16_t evaluate_move(uint32_t encoded_move, uint16_t mat, int8_t depth = -1);

}  // namespace Chess
}  // namespace LBR