#include "bishop_moves.h"
#include "chess_board.h"

namespace LBR
{
namespace Chess
{
uint64_t get_bishop_attacks(uint64_t square, uint64_t occupied,
                            uint64_t diag_mask, uint64_t anti_diag_mask)
{
    return get_ray_attacks(square, occupied, diag_mask) |
           get_ray_attacks(square, occupied, anti_diag_mask);
}

uint8_t bishop_moves(ChessBoard& board, int8_t color)
{
    uint64_t bishops = color > 0 ? board.w_bishops : board.b_bishops;
    uint64_t occupied = board.white_pieces() | board.black_pieces();
    uint64_t friendlies =
        color > 0 ? board.white_pieces() : board.black_pieces();
    uint64_t ret{0};
    uint64_t enemies = color < 0 ? board.white_pieces() : board.black_pieces();
    uint8_t color_flag = color > 0 ? WHITE_FLAG : BLACK_FLAG;

    uint8_t len = extract_offsets(bishops);
    while (len--)
    {
        uint8_t offset;
        extracted_offsets_stack.pop(offset);
        uint8_t move_len = extract_offsets(
            get_bishop_attacks(1ULL << offset, occupied, DIAG_ATTACKS[offset],
                               ANTI_DIAG_ATTACKS[offset]));
        while (move_len--)
        {
            uint8_t end_offset;
            extracted_offsets_stack.pop(end_offset);
            uint64_t end_sq = 1ULL << end_offset;
            if (end_sq & ~friendlies)
            {
                int8_t piece = board.get_piece_at_pos(end_sq);
                uint8_t piece_captured = piece >= 0 ? piece : -piece;
                encoded_moves_stack.push(encode_move(
                    color_flag, BISHOP, offset, piece_captured, end_offset, 0));
            }
        }
    }
}
}  // namespace Chess

}  // namespace LBR
