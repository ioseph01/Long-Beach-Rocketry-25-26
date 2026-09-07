#include "chess_globals.h"
#include <bit>

namespace LBR
{
namespace Chess
{

uint16_t PIECE_TO_VAL(uint8_t pieceFlag)
{
    switch (pieceFlag)
    {
        case PAWN:
            return PAWN_VALUE;
        case KNIGHT:
        case PROMOTE_KNIGHT_FLAG:
            return KNIGHT_VALUE;
        case BISHOP:
        case PROMOTE_BISHOP_FLAG:
            return BISHOP_VALUE;
        case ROOK:
        case PROMOTE_ROOK_FLAG:
            return ROOK_VALUE;
        case QUEEN:
        case PROMOTE_QUEEN_FLAG:
            return QUEEN_VALUE;
        case KING:
            return KING_VALUE;
    }
    return 0;
}

uint16_t PROMOTION_VAL(uint8_t piece)
{
    return piece == KNIGHT ? 2 * PIECE_TO_VAL(piece) : PIECE_TO_VAL(piece);
}

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

uint32_t encode_log_entry(uint32_t move, bool w_king_castle,
                          bool w_queen_castle, bool b_king_castle,
                          bool b_queen_castle)
{
    return (static_cast<uint32_t>(w_king_castle) << 26) |
           (static_cast<uint32_t>(w_queen_castle) << 25) |
           (static_cast<uint32_t>(b_king_castle) << 24) |
           (static_cast<uint32_t>(b_queen_castle) << 23) | move;
}

ChessEntry decode_log_entry(uint32_t encoded_entry)
{
    return ChessEntry{
        .encoded_move = encoded_entry & 0x7FFFFF,
        .w_king_castle = static_cast<bool>(encoded_entry & (1U << 26)),
        .w_queen_castle = static_cast<bool>(encoded_entry & (1U << 25)),
        .b_king_castle = static_cast<bool>(encoded_entry & (1U << 24)),
        .b_queen_castle = static_cast<bool>(encoded_entry & (1U << 23))};
}

void extract_offsets(uint64_t bitboard)
{
    while (bitboard)
    {
        extracted_offsets_stack.push(
            static_cast<uint8_t>(std::countr_zero(bitboard)));
        bitboard &= bitboard - 1;
    }
}

uint16_t evaluate_move(uint32_t encoded_move, uint16_t mat, int8_t depth = -1)
{
    ChessMove move = decode_move(encoded_move);
    uint16_t score{0};

    /* Handle PST */

    if (move.color == BLACK_FLAG)
    {
        move.start_offset ^= 56;
        move.end_offset ^= 56;
    }
    // switch (move.piece)
    // {
    //     case PAWN:
    //         /* code */
    //         break;

    //     default:
    //         break;
    // }

    /* Handle flags */
    if (move.captured_piece != 0 && move.is_promotion())
    {
        return score + CAPTURE_VALUE + 10 * PIECE_TO_VAL(move.captured_piece) -
               PIECE_TO_VAL(move.piece) + PROMOTION_VAL(move.flags);
    }
    else if (move.is_promotion())
    {
        return score + PROMOTION_VAL(move.flags);
    }
    else if (move.captured_piece)
    {
        return score + CAPTURE_VALUE + 10 * PIECE_TO_VAL(move.captured_piece) -
               PIECE_TO_VAL(move.piece);
    }
    else if (move.flags == CASTLE_KINGSIDE_FLAG ||
             move.flags == CASTLE_QUEENSIDE_FLAG)
    {
        return CASTLE_VALUE + score;
    }

    if (depth >= 0)
    {
        if (encoded_move == KILLER_MOVES[depth][0])
        {
            return KILLER_VALUE_1 + score;
        }
        else if (encoded_move == KILLER_MOVES[depth][1])
        {
            return KILLER_VALUE_2 + score;
        }
    }
    return score;
}

}  // namespace Chess
}  // namespace LBR