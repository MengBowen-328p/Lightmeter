//
// Created by 15216 on 2023/11/17.
//

#ifndef FIRMWARE_OLED_H
#define FIRMWARE_OLED_H

#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

#define OLED_SCL_PIN PB14
#define OLED_SDA_PIN PB13

class OLED
{
public:
    void oledInit(void);
    void showStartScreen(void);
    void showMenu(void);
};

#endif //FIRMWARE_OLED_H
