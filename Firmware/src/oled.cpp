//
// Created by 15216 on 2023/11/17.
//

#include "oled.h"

U8G2_SSD1306_128X64_NONAME_1_HW_I2C Screen(U8G2_R0,U8X8_PIN_NONE,OLED_SCL_PIN,OLED_SDA_PIN);

void OLED::oledInit(void)
{
    Screen.begin();
}

void OLED::showStartScreen(void)            //Show Start Page
{
    Screen.setFont(u8g2_font_04b_03_tr);
    Screen.setCursor(64,0);
    Screen.print("CUBE Lightmeter!");
    Screen.sendBuffer();
    delay(1000);
}

void OLED::showMenu(void)
{
    Screen.setFont(u8g2_font_04b_03_tr);
    Screen.setCursor(0,0);
    Screen.sendBuffer();
}