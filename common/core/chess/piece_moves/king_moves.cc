#include "king_moves.h"
#include "chess_board.h"

namespace LBR
{
namespace Chess
{

uint64_t king_destinations(ChessBoard& board, int8_t color, int8_t offset)
{
    uint64_t occupied = board.black_pieces() | board.white_pieces();
    uint64_t destinations = KING_ATTACKS[offset];
    uint64_t friendlies =
        color > 0 ? board.white_pieces() : board.black_pieces();

    if (color > 0)
    {
        uint64_t friendlies = board.white_pieces();
        if (offset == E1_OFFSET && !in_check(board, color))
        {
            if (board.w_castle_kingside && occupied & W_KINGSIDE_PATH == 0)
            {
                if (!board.is_attacked(F1, -color))
                {
                    destinations |= W_KINGSIDE_KING_POS;
                }
            }
            if (board.w_castle_queenside && occupied & W_QUEENSIDE_PATH == 0)
            {
                if (!board.is_attacked(D1, -color))
                {
                    destinations |= W_QUEENSIDE_KING_POS;
                }
            }
        }
    }
    else if (color < 0)
    {
        uint64_t friendlies = board.black_pieces();
        if (offset == E8_OFFSET && !in_check(board, color))
        {
            if (board.b_castle_kingside && occupied & B_KINGSIDE_PATH == 0)
            {
                if (!board.is_attacked(F8, -color))
                {
                    destinations |= B_KINGSIDE_KING_POS;
                }
            }
            if (board.b_castle_queenside && occupied & B_QUEENSIDE_PATH == 0)
            {
                if (!board.is_attacked(D8, -color))
                {
                    destinations |= B_QUEENSIDE_KING_POS;
                }
            }
        }
    }
    return destinations & ~friendlies;
}
uint8_t king_moves(ChessBoard& board, int8_t color, int8_t offset)
{
    uint8_t ret{0};
    uint64_t destinations = king_destinations(board, color, offset);
    int8_t color_flag = color > 0 ? WHITE_FLAG : BLACK_FLAG;
    uint64_t enemies = color > 0 ? board.black_pieces() : board.white_pieces();
    uint8_t len = extract_offsets(destinations);
    while (len--)
    {
        uint8_t destination;
        extracted_offsets_stack.pop(destination);
        uint64_t end_sq = 1ULL << destination;
        uint8_t flag{0};
        uint8_t captured_piece{0};

        if (enemies & end_sq)
        {
            int8_t piece = board.get_piece_at_pos(end_sq);
            captured_piece = captured_piece > 0 ? piece : -piece;
        }
        else if (destination - offset == 2 || offset - destination == 2)
        {
            flag = destination & G_FILE ? CASTLE_KINGSIDE_FLAG
                                        : CASTLE_QUEENSIDE_FLAG;
        }
        encoded_moves_stack.push(encode_move(
            color_flag, KING, offset, captured_piece, destination, flag));

        ++ret;
    }
    return ret;
}

uint8_t in_check(ChessBoard& board, int8_t enemy_color)
{

    return board.is_attacked(enemy_color < 0 ? board.w_king : board.b_king,
                             enemy_color);
}

}  // namespace Chess
}  // namespace LBR