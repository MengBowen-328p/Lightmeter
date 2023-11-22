//
// Created by 15216 on 2023/11/17.
//

#include "oled.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C screen(U8G2_R0, U8X8_PIN_NONE, PB6, PB7);

void OLED::oledInit(void)
{
    screen.begin();
}

void OLED::showStartScreen(void)            //Show Start Page
{
    screen.setFont(u8g2_font_DigitalDiscoThin_te);
    screen.setCursor(0, 12);
    screen.print("C U B E");
    screen.setCursor(0, 36);
    screen.print("L i g h t M e t e r");
    screen.drawFrame(0, 52, 128, 12);
    for (uint8_t i = 0; i < 125; i++)
    {
        screen.drawBox(2, 54, i, 8);
        screen.sendBuffer();
        delay(20);
        if (i == 100)
        {
            delay(2000);
        }
    }
    screen.clearBuffer();
    screen.clearDisplay();
}

void OLED::showMainMenu(uint8_t menu_page)
{
    switch (menu_page)
    {
        case 1:
            showLuxMenu();
        case 2:
            showNDMenu();
        case 4:
            showLuxMenu();
    }
}

void OLED::showLuxMenu(void)
{
    for (uint8_t i = 20; i < 33; i++)
    {
        screen.setFont(u8g2_font_streamline_logo_t);
        screen.drawGlyph(52, i, 0x0038);
        screen.sendBuffer();
        screen.clearBuffer();
        delayMicroseconds(5);
    }
    for (uint8_t j = 32; j > 28; j--)
    {
        screen.setFont(u8g2_font_streamline_logo_t);
        screen.drawGlyph(52, j, 0x0038);
        screen.sendBuffer();
        screen.clearBuffer();

        if (j == 29)
        {
            screen.setFont(u8g2_font_streamline_logo_t);
            screen.drawGlyph(52, j, 0x0038);
        }
        delay(1);
    }
    screen.setFont(u8g2_font_DigitalDiscoThin_te);
    screen.setCursor(36, 50);
    screen.drawBox(10,60,108,2);
    screen.drawBox(10,58,4,8);
    screen.print("GET LUX");
    screen.sendBuffer();
}

void OLED::showNDMenu(void)
{
    for (uint8_t i = 20; i < 33; i++)
    {
        screen.setFont(u8g2_font_streamline_photography_t);
        screen.drawGlyph(52, i, 0x0030);
        screen.sendBuffer();
        screen.clearBuffer();
        delayMicroseconds(5);
    }
    for (uint8_t j = 32; j > 28; j--)
    {
        screen.setFont(u8g2_font_streamline_photography_t);
        screen.drawGlyph(52, j, 0x0030);
        screen.sendBuffer();
        screen.clearBuffer();

        if (j == 29)
        {
            screen.setFont(u8g2_font_streamline_photography_t);
            screen.drawGlyph(52, j, 0x0030);
        }
        delay(1);
    }
    screen.setFont(u8g2_font_DigitalDiscoThin_te);
    screen.setCursor(38, 50);
    screen.drawBox(10,60,108,2);
    screen.drawBox(62,58,4,8);
    screen.print("GET ND");
    screen.sendBuffer();
}

