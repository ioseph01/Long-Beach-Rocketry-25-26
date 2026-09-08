/**
 * @file board.h
 */

#pragma once
#include "gpio.h"
#include "usart.h"

#include <vector>

extern uint8_t rxb;

namespace LBR
{

struct Board
{
    Usart& usart;

    Gpio& rx;
    Gpio& tx;
};

bool bsp_init(void);
Board& get_board(void);

}  // namespace LBR