#include "pawn_moves.h"
#include <bit>
#include "chess_board.h"

namespace LBR
{
namespace Chess
{
uint8_t pawn_moves(ChessBoard& board, int8_t color)
{
    uint64_t white_pieces = board.white_pieces();
    uint64_t black_pieces = board.white_pieces();
    uint64_t occupied = white_pieces | black_pieces;
    uint64_t free = ~occupied;
    int8_t color_flag = color > 0 ? WHITE_FLAG : BLACK_FLAG;
    ChessMove move{.end_offset = 0, .flags = 0};
    if (color > 0)
    {
        uint64_t pawns = board.w_pawns;
        uint64_t single_push = (pawns << 8) & free;
        uint64_t double_push = (single_push << 8) & free & RANK4;
        uint64_t capt_right = (pawns << 9) & black_pieces & ~A_FILE;
        uint64_t capt_left = (pawns << 7) & black_pieces & ~H_FILE;

        /* TODO: Handle PASSANT */
        return process_pawn_moves(board, color_flag, single_push, 8) +
               process_pawn_moves(board, color_flag, double_push, 16) +
               process_pawn_moves(board, color_flag, capt_right, 9) +
               process_pawn_moves(board, color_flag, capt_left, 7);
    }
    else if (color < 0)
    {
        uint64_t pawns = board.b_pawns;
        uint64_t single_push = (pawns >> 8) & free;
        uint64_t double_push = (single_push >> 8) & free & RANK5;
        uint64_t capt_right = (pawns >> 7) & white_pieces & ~A_FILE;
        uint64_t capt_left = (pawns >> 9) & white_pieces & ~H_FILE;

        /* TODO: Handle PASSANT */
        return process_pawn_moves(board, color_flag, single_push, -8) +
               process_pawn_moves(board, color_flag, double_push, -16) +
               process_pawn_moves(board, color_flag, capt_right, -7) +
               process_pawn_moves(board, color_flag, capt_left, -9);
    }
}

uint8_t process_pawn_moves(ChessBoard& board, uint8_t color,
                           uint64_t destinations, int8_t shift)
{
    uint8_t ret{0};
    while (destinations)
    {
        ++ret;
        uint8_t target = std::countr_zero(destinations) - 1;
        uint8_t start = target - shift;
        ChessMove move;
        if (shift == 16 || shift == -16)
        {
            move.flags = DOUBLE_PUSH_FLAG;
        }
        else if (shift % 2 == 1)
        {
            int8_t captured_piece = board.get_piece_at_pos(1ULL << target);
            move.captured_piece =
                captured_piece >= 0 ? captured_piece : -captured_piece;
            if (captured_piece == 0)
            {
                move.flags = PASSANT_FLAG;
                move.captured_piece = PAWN;
            }
        }
        if ((1ULL << target) & (RANK1 | RANK8))
        {
            encoded_moves_stack.push(encode_move(color, PAWN, start,
                                                 move.captured_piece, target,
                                                 PROMOTE_QUEEN_FLAG));
            encoded_moves_stack.push(encode_move(color, PAWN, start,
                                                 move.captured_piece, target,
                                                 PROMOTE_KNIGHT_FLAG));
            encoded_moves_stack.push(encode_move(color, PAWN, start,
                                                 move.captured_piece, target,
                                                 PROMOTE_ROOK_FLAG));
            encoded_moves_stack.push(encode_move(color, PAWN, start,
                                                 move.captured_piece, target,
                                                 PROMOTE_BISHOP_FLAG));
        }
        else
        {
            encoded_moves_stack.push(encode_move(
                color, PAWN, start, move.captured_piece, target, move.flags));
        }
    }
    return ret;
}
}  // namespace Chess
}  // namespace LBR