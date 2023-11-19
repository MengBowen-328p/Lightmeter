//
// Created by 15216 on 2023/11/17.
//

#include "button.h"

void Button::buttonInit(void)
{
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_ENTER, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
}

uint8_t Button::buttonScan(void)
{
    uint8_t button_state = 0;
    if (digitalRead(BUTTON_UP) == 0)
    {
        button_state = 1;
    }
    else if (digitalRead(BUTTON_ENTER) == 0)
    {
        button_state = 2;
    }
    else if (digitalRead(BUTTON_DOWN == 0))
    {
        button_state = 3;
    }
    return button_state;
    button_state = 0;
}


