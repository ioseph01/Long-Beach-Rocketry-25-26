/**
 * @file chess_manager.h
 * @brief This module manages the game including player input and output
 */

#pragma once
#include <span>

#include "chess_board.h"
#include "chess_globals.h"

namespace LBR
{
namespace Chess
{

class ChessManager
{
public:
    ChessManager();

    bool process_input(const char* input);

    void render_board();

    std::span<const uint8_t> board_data() const;

    int8_t turn;

private:
    char board_str[64 * 4 + 6 * 8]{'a', ' ', 'b', ' ', 'c', ' ', 'd',  ' ', 'e',
                                   ' ', 'f', ' ', 'g', ' ', 'h', '\r', '\n'};
    ChessBoard board;
    int8_t player_turn;
};

}  // namespace Chess
}  // namespace LBR