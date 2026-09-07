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
    bool init();

    void render_board();

    std::span<const uint8_t> board_data() const;

private:
    char board_str[64 * 4 + 6 * 8]{'a', ' ', 'b', ' ', 'c', ' ', 'd',  ' ', 'e',
                                   ' ', 'f', ' ', 'g', ' ', 'h', '\r', '\n'};
    ChessBoard board;
};

}  // namespace Chess
}  // namespace LBR