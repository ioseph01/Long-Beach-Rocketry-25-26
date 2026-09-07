#include "chess_manager.h"

namespace LBR
{
namespace Chess
{
bool ChessManager::init()
{
    board = ChessBoard();
    return true;
}

void ChessManager::render_board()
{
    int j{18};
    for (int i = 0; i < 64; i++)
    {

        int8_t piece = board.get_piece_at_pos(1ULL << i);

        switch (piece)
        {
            case 0:
                board_str[j] = '.';
                board_str[j + 1] = ' ';
                j += 2;
                break;
            case PAWN:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x99';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case -PAWN:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x9F';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case KNIGHT:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x98';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case -KNIGHT:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x9E';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case BISHOP:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x97';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case -BISHOP:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x9D';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case ROOK:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x9D';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case -ROOK:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x9D';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case QUEEN:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x95';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case -QUEEN:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x9B';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case KING:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x94';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case -KING:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x9A';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            default:
                board_str[j] = ' ';
                board_str[j + 1] = '.';
                board_str[j + 2] = ' ';
                j += 3;
                break;
        }
        if (i > 0 && i % 8 == 7)
        {
            board_str[j++] = (1 + (i / 8)) + '0';
            board_str[j++] = '\r';
            board_str[j++] = '\n';
            continue;
        }
    }
}

std::span<const uint8_t> ChessManager::board_data() const
{
    return {reinterpret_cast<const uint8_t*>(board_str), sizeof(board_str)};
}
}  // namespace Chess
}  // namespace LBR