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

    /**
     * @brief Handles input from the player
     * @param input A 5 char string that will be analyzed
     * 
     * @return true if successful, false otherwise
     */
    bool process_input(const char* input);

    /**
     * @brief Mutates the board string to represent the current position
     */
    void render_board(void);

    /**
     * @brief Converts the board string to a span to output in uart
     */
    std::span<const uint8_t> board_data(void) const;

    /**
     * @brief The current side to move
     */
    int8_t turn;

private:
    char board_str[64 * 4 + 6 * 8]{'a', ' ', 'b', ' ', 'c', ' ', 'd',  ' ', 'e',
                                   ' ', 'f', ' ', 'g', ' ', 'h', '\r', '\n'};
    ChessBoard board;
    int8_t player_turn;
};

}  // namespace Chess
}  // namespace LBR