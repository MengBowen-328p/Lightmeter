#include "switch.h"

static uint8_t keyupstate     = 0;
static uint8_t keymiddlestate = 0;
static uint8_t keydownstate   = 0;

void switchInit(void)
{
    __RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.IT    = GPIO_IT_FALLING;
    GPIO_InitStruct.Pins  = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

    GPIO_Init(CW_GPIOB, &GPIO_InitStruct);

    GPIO_ConfigFilter(CW_GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2, GPIO_FLTCLK_RC150K);
    GPIOB_INTFLAG_CLR(GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);
    NVIC_EnableIRQ(GPIOB_IRQn);
}

uint8_t switchClick(void)
{
    if (CW_GPIOB->ISR_f.PIN1) {
        keyupstate = 1;
        GPIOB_INTFLAG_CLR(GPIO_PIN_0);
        if (keyupstate == 1) {
            keyupstate = 0;
        }
        return 1;
    } else if (CW_GPIOB->ISR_f.PIN1) {
        keymiddlestate = 1;
        GPIOB_INTFLAG_CLR(GPIO_PIN_1);
        if (keymiddlestate == 1) {
            keymiddlestate = 0;
        }
        return 2;
    } else if (CW_GPIOB->ISR_f.PIN2) {
        GPIOB_INTFLAG_CLR(GPIO_PIN_2);
        if (keydownstate == 1) {
            keydownstate = 0;
        }
        return 3;
    }
    return 0;
}

void GPIOB_IRQHandlerCallback(void)
{
    switchClick();
}
