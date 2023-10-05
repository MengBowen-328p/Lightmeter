#ifndef __OLED_H
#define __OLED_H

#include "cw32f030_gpio.h"
#include "cw32f030_i2c.h"

#define OLED_I2C_GPIOPort CW_GPIOB
#define OLED_SDA_PIN      GPIO_PIN_14
#define OLED_SCL_PIN      GPIO_PIN_13

#define OLED_ADDR         0x78
#define CMD_RES           0x00
#define DATA_RES          0x40

#define DISPLAY_ON 0xAF
#define DISPLAY_OFF 0XAE
#endif