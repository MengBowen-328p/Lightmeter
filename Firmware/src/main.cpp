#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <BH1750.h>
#include <button.h>
#include <oled.h>

OLED oled;
Button button;



//TwoWire oled_wire(PB13,PB14);



void setup() {
oled.oledInit();
button.buttonInit();
// write your initialization code here
}

void loop() {
// write your code here
}