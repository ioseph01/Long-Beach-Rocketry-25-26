#include "chess_board.h"

namespace LBR
{
namespace Chess
{

uint64_t ChessBoard::white_pieces() const
{
    return this->w_pawns | this->w_knights | this->w_bishops | this->w_rooks |
           this->w_queens | this->w_king;
}
uint64_t ChessBoard::black_pieces() const
{
    return this->b_pawns | this->b_knights | this->b_bishops | this->b_rooks |
           this->b_queens | this->b_king;
}

void simulate(uint64_t encoded_move)
{
}
void undo()
{
}
int8_t ChessBoard::get_piece_at_pos(uint64_t pos) const
{
    if (pos & w_pawns)
    {
        return PAWN;
    }
    else if (pos & b_pawns)
    {
        return -PAWN;
    }
    else if (pos & w_knights)
    {
        return KNIGHT;
    }
    else if (pos & b_knights)
    {
        return -KNIGHT;
    }
    else if (pos & w_bishops)
    {
        return BISHOP;
    }
    else if (pos & b_bishops)
    {
        return -BISHOP;
    }
    else if (pos & w_rooks)
    {
        return ROOK;
    }
    else if (pos & b_rooks)
    {
        return -ROOK;
    }
    else if (pos & w_queens)
    {
        return QUEEN;
    }
    else if (pos & b_queens)
    {
        return -QUEEN;
    }
    else if (pos & w_king)
    {
        return KING;
    }
    else if (pos & b_king)
    {
        return -KING;
    }
    return 0;
}

int16_t ChessBoard::evaluate() const
{
    int16_t score{0};

    for (uint8_t i = 0; i < extract_offsets(white_pieces()); i++)
    {
        uint8_t offset;
        extracted_offsets_stack.pop(offset);
        int8_t piece = get_piece_at_pos(1ULL << offset);
        if (0 < piece && piece < 7)
        {
            score += PIECE_TO_VAL(piece);
        }
    }
    for (uint8_t i = 0; i < extract_offsets(black_pieces()); i++)
    {
        uint8_t offset;
        extracted_offsets_stack.pop(offset);
        int8_t piece = -get_piece_at_pos(1ULL << offset);
        if (0 < piece && piece < 7)
        {
            score -= PIECE_TO_VAL(piece);
        }
    }
    return score;
}

}  // namespace Chess

}  // namespace LBR