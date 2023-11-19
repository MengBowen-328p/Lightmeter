#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <BH1750.h>
#include <button.h>
#include <oled.h>

uint8_t  button_state = 0;

OLED oled;
Button button;



//TwoWire oled_wire(PB13,PB14);



void setup() {
oled.oledInit();
button.buttonInit();
// write your initialization code here
}

void loop() {
    button_state = button.buttonScan();
// write your code here
}