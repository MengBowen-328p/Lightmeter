//
// Created by 15216 on 2023/11/17.
//

#ifndef FIRMWARE_BUTTON_H
#define FIRMWARE_BUTTON_H

#include <Arduino.h>

#define BUTTON_UP PB13
#define BUTTON_ENTER PB14
#define BUTTON_DOWN PB15

class Button
{
public:
    void buttonInit(void);

    uint8_t buttonScan(void);
};

#endif //FIRMWARE_BUTTON_H
