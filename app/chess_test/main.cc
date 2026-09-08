#include "board.h"
#include "chess_manager.h"

using namespace LBR;

Chess::ChessManager manager;
uint8_t rxb;
std::array<uint8_t, 17> txb{"i <3 embedded\r\n"};

int main(int argc, char** argv)
{
    bsp_init();

    Board hw = get_board();
    manager.render_board();

    while (1)
    {
        hw.usart.send(manager.board_data());
        hw.usart.send(txb);

        // Busy wait
        for (volatile uint32_t i = 0; i < 1000000; i++)
        {
        }
    }

    return 0;
}
