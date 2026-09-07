#pragma once
#include "chess_globals.h"
namespace LBR
{
namespace Chess
{

uint64_t get_current_rank(uint64_t square)
{
    if (square & RANK1)
    {
        return RANK1;
    }
    if (square & RANK2)
    {
        return RANK2;
    }
    if (square & RANK3)
    {
        return RANK3;
    }
    if (square & RANK4)
    {
        return RANK4;
    }
    if (square & RANK5)
    {
        return RANK5;
    }
    if (square & RANK6)
    {
        return RANK6;
    }
    if (square & RANK7)
    {
        return RANK7;
    }
    if (square & RANK8)
    {
        return RANK8;
    }
    return 0;
}
uint64_t get_current_file(uint64_t square)
{
    if (square & A_FILE)
    {
        return A_FILE;
    }
    if (square & B_FILE)
    {
        return B_FILE;
    }
    if (square & C_FILE)
    {
        return C_FILE;
    }
    if (square & D_FILE)
    {
        return D_FILE;
    }
    if (square & E_FILE)
    {
        return E_FILE;
    }
    if (square & F_FILE)
    {
        return F_FILE;
    }
    if (square & G_FILE)
    {
        return G_FILE;
    }
    if (square & H_FILE)
    {
        return H_FILE;
    }
    return 0;
}

uint64_t reverse_bits(uint64_t bits)
{
    bits = ((bits & 0xFFFFFFFF00000000) >> 32) |
           ((bits & 0x00000000FFFFFFFF) << 32);
    bits = ((bits & 0xFFFF0000FFFF0000) >> 16) |
           ((bits & 0x0000FFFF0000FFFF) << 16);
    bits =
        ((bits & 0xFF00FF00FF00FF00) >> 8) | ((bits & 0x00FF00FF00FF00FF) << 8);
    bits =
        ((bits & 0xF0F0F0F0F0F0F0F0) >> 4) | ((bits & 0x0F0F0F0F0F0F0F0F) << 4);
    bits =
        ((bits & 0xCCCCCCCCCCCCCCCC) >> 2) | ((bits & 0x3333333333333333) << 2);
    bits =
        ((bits & 0xAAAAAAAAAAAAAAAA) >> 1) | ((bits & 0x5555555555555555) << 1);
    return bits & SET_BITMASK;
}

uint64_t get_ray_attacks(uint64_t bitboard, uint64_t occupied, uint64_t mask)
{
    uint64_t vector_occ = occupied & mask;
    uint64_t pos_attacks = (vector_occ ^ (vector_occ - bitboard * 2)) & mask;
    uint64_t rev_piece = reverse_bits(bitboard);
    uint64_t rev_occupied = reverse_bits(vector_occ);
    uint64_t rev_mask = reverse_bits(mask);
    uint64_t rev_neg_attacks =
        (rev_occupied ^ ((rev_occupied - rev_piece * 2) & SET_BITMASK)) &
        rev_mask;

    uint64_t neg_attacks = reverse_bits(rev_neg_attacks);
    return pos_attacks | neg_attacks;
}

uint32_t encode_move(uint8_t color, uint8_t piece, uint8_t start_offset,
                     uint8_t captured_piece, uint8_t end_offset,
                     uint8_t misc_flags)
{
    return (static_cast<uint32_t>(color) << 0) |
           (static_cast<uint32_t>(piece) << 1) |
           (static_cast<uint32_t>(start_offset) << 4) |
           (static_cast<uint32_t>(captured_piece) << 10) |
           (static_cast<uint32_t>(end_offset) << 13) |
           (static_cast<uint32_t>(misc_flags) << 19);
}

ChessMove decode_move(uint32_t move)
{
    return ChessMove{
        .color = static_cast<uint8_t>(0b1 & (move >> 0)),
        .piece = static_cast<uint8_t>(0b111 & (move >> 1)),
        .start_offset = static_cast<uint8_t>(0b111111 & (move >> 4)),
        .captured_piece = static_cast<uint8_t>(0b111 & (move >> 10)),
        .end_offset = static_cast<uint8_t>(0b111111 & (move >> 13)),
        .flags = static_cast<uint8_t>(0b1111 & (move >> 19)),
    };
}

}  // namespace Chess
}  // namespace LBR