#include "chess_manager.h"

namespace LBR
{
namespace Chess
{
ChessManager::ChessManager()
    : turn(1), player_turn(-1), board(ChessBoard(*this))
{
}

bool ChessManager::process_input(const char* input)
{
    char r1 = input[0];
    char f1 = input[1];
    if (!(f1 >= 'A' && f1 <= 'H') && !(f1 >= 'a' && f1 <= 'h'))
    {
        return false;
    }
    if (!(r1 >= '1' && r1 <= '8'))
    {
        return false;
    }
    char r2 = input[2];
    char f2 = input[3];
    if (!(f2 >= 'A' && f2 <= 'H') && !(f2 >= 'a' && f2 <= 'h'))
    {
        return false;
    }
    if (!(r2 >= '1' && r2 <= '8'))
    {
        return false;
    }

    switch (input[4])
    {
        case ' ':
            break;
        case 'Q':
        case 'q':
            break;
        case 'N':
        case 'n':
            break;
        case 'R':
        case 'r':
            break;
        case 'B':
        case 'b':
            break;
        default:
            return false;
    }
    return true;
}

void ChessManager::render_board(void)
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
                board_str[j + 2] = '\x96';
                board_str[j + 3] = ' ';
                j += 4;
                break;
            case -ROOK:
                board_str[j] = '\xE2';
                board_str[j + 1] = '\x99';
                board_str[j + 2] = '\x9C';
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

std::span<const uint8_t> ChessManager::board_data(void) const
{
    return {reinterpret_cast<const uint8_t*>(board_str), sizeof(board_str)};
}
}  // namespace Chess
}  // namespace LBR