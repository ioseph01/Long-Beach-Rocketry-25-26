#include "queen_moves.h"
#include "chess_board.h"

namespace LBR
{

namespace Chess
{

uint64_t get_queen_attacks(uint64_t square, uint64_t occupied,
                           uint64_t rank_mask, uint64_t file_mask,
                           uint64_t diag_mask, uint64_t anti_diag_mask)
{
    return get_ray_attacks(square, occupied, rank_mask) |
           get_ray_attacks(square, occupied, file_mask) |
           get_ray_attacks(square, occupied, diag_mask) |
           get_ray_attacks(square, occupied, anti_diag_mask);
}

uint8_t queen_moves(ChessBoard& board, int8_t color)
{
    uint64_t queens = color > 0 ? board.w_queens : board.b_queens;
    uint64_t occupied = board.white_pieces() | board.black_pieces();
    uint64_t friendlies =
        color > 0 ? board.white_pieces() : board.black_pieces();
    uint64_t enemies = color < 0 ? board.white_pieces() : board.black_pieces();
    uint8_t color_flag = color > 0 ? WHITE_FLAG : BLACK_FLAG;
    uint8_t ret{0};

    uint8_t queen_len = extract_offsets(queens);
    while (queen_len--)
    {
        uint8_t offset;
        extracted_offsets_stack.pop(offset);
        uint64_t square = 1ULL << offset;

        uint8_t move_len = extract_offsets(
            get_queen_attacks(square, occupied, get_current_rank(square),
                              get_current_file(square), DIAG_ATTACKS[offset],
                              ANTI_DIAG_ATTACKS[offset]));
        while (move_len--)
        {
            uint8_t end_offset;
            extracted_offsets_stack.pop(end_offset);
            uint64_t end_square = 1ULL << end_offset;
            if (end_square & ~friendlies)
            {
                uint8_t captured_piece;
                int8_t tmp = board.get_piece_at_pos(end_square);
                captured_piece = tmp >= 0 ? tmp : -tmp;
                encoded_moves_stack.push(encode_move(
                    color_flag, QUEEN, offset, captured_piece, end_offset, 0));
                ++ret;
            }
        }
    }
    return ret;
}

}  // namespace Chess
}  // namespace LBR