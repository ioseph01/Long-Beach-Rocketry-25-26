#include "rook_moves.h"
#include "chess_board.h"

namespace LBR
{
namespace Chess
{

uint64_t get_rook_attacks(uint64_t square, uint64_t occupied,
                          uint64_t rank_mask, uint64_t file_mask)
{
    return get_ray_attacks(square, occupied, rank_mask) |
           get_ray_attacks(square, occupied, file_mask);
}

uint64_t rook_move_mask(ChessBoard& board, int8_t color)
{
    uint64_t rooks = color > 0 ? board.w_rooks : board.b_rooks;
    uint64_t occupied = board.white_pieces() | board.black_pieces();
    uint64_t friendlies =
        color > 0 ? board.white_pieces() : board.black_pieces();
    uint64_t ret{0};
    uint8_t len = extract_offsets(rooks);
    while (len)
    {
        uint8_t offset;
        extracted_offsets_stack.pop(offset);
        ret |= get_rook_attacks(1ULL << offset, occupied,
                                get_current_rank(1ULL << offset),
                                get_current_file(1ULL << offset));
        --len;
    }
    return ret & ~friendlies;
}

uint8_t rook_moves(ChessBoard& board, int8_t color)
{
    uint64_t rooks = color > 0 ? board.w_rooks : board.b_rooks;
    uint64_t occupied = board.white_pieces() | board.black_pieces();
    uint64_t friendlies =
        color > 0 ? board.white_pieces() : board.black_pieces();
    uint64_t enemies = color < 0 ? board.white_pieces() : board.black_pieces();
    uint8_t color_flag = color > 0 ? WHITE_FLAG : BLACK_FLAG;
    uint8_t ret{0};

    uint8_t rook_len = extract_offsets(rooks);
    while (rook_len)
    {
        uint8_t offset;
        extracted_offsets_stack.pop(offset);
        uint64_t square = 1ULL << offset;
        uint8_t move_len = extract_offsets(
            get_rook_attacks(square, occupied, get_current_file(square),
                             get_current_rank(square)));
        while (move_len)
        {
            uint8_t end_offset;
            uint64_t end_square = 1ULL << end_offset;
            extracted_offsets_stack.pop(end_offset);
            uint8_t captured_piece{0};
            if (end_square & enemies)
            {
                int8_t tmp = board.get_piece_at_pos(end_square);
                captured_piece = tmp > 0 ? tmp : -tmp;
            }
            encoded_moves_stack.push(encode_move(
                color_flag, ROOK, offset, captured_piece, end_offset, 0));
            --move_len;
            ++ret;
        }

        --rook_len;
    }
    return ret;
}

}  // namespace Chess
}  // namespace LBR