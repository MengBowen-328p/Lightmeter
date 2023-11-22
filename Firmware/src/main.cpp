#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <BH1750.h>
#include <button.h>
#include <oled.h>
#include <index.h>

uint8_t  button_state = 0;
BH1750 bh1750;
OLED oled;
Button button;
TwoWire bh1850_wire(PB11,PB10);

//TwoWire oled_wire(PB13,PB14);



void setup() {
oled.oledInit();
button.buttonInit();
bh1750.begin(BH1750::CONTINUOUS_HIGH_RES_MODE,0x23,&bh1850_wire);
// write your initialization code here
}

void loop() {
    button_state = button.buttonScan();
// write your code here
}