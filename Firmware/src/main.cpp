#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <BH1750.h>
#include <button.h>
#include <oled.h>
#include <index.h>



TwoWire oled_wire(PB7,PB6);
OLED oled;
Button button;
uint8_t menu_page = 2;


void setup()
{

    oled.oledInit();
    button.buttonInit();
    oled.showStartScreen();

}

void loop()
{
    oled.showLuxMenu();
    delay(2000);
    oled.showNDMenu();
    delay(2000);
}