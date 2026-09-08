#include "knight_moves.h"
#include "chess_board.h"

namespace LBR
{
namespace Chess
{

uint64_t knight_destinations(ChessBoard& board, int8_t color, uint8_t offset)
{
    uint64_t friendlies =
        board.white_pieces() ? color > 0 : board.black_pieces();
    return KNIGHT_ATTACKS[offset] & ~friendlies;
}
uint8_t knight_moves(ChessBoard& board, int8_t color, uint8_t offset)
{
    int8_t ret{0};
    uint64_t destinations = knight_destinations(board, color, offset);
    uint8_t color_flag = color > 0 ? WHITE_FLAG : BLACK_FLAG;
    uint64_t enemies = color > 0 ? board.black_pieces() : board.white_pieces();
    uint8_t len = extract_offsets(destinations);
    while (len)
    {
        uint8_t end_offset;
        extracted_offsets_stack.pop(end_offset);
        uint64_t end_sq = 1ULL << end_offset;
        int8_t piece = board.get_piece_at_pos(end_sq);
        encoded_moves_stack.push(encode_move(color_flag, KNIGHT, offset,
                                             piece >= 0 ? piece : -piece,
                                             end_offset, 0));

        --len;
        ++ret;
    }
    return ret;
}

}  // namespace Chess
}  // namespace LBR