#ifndef __RCC_H
#define __RCC_H

#include "rcc.h"

void rccInitHSE(void)
{
    RCC_HSI_Enable(RCC_HSIOSC_DIV6);
    RCC_HCLKPRS_Config(RCC_HCLK_DIV1);
    RCC_PLL_Enable(RCC_PLLSOURCE_HSI,8000000,8);
    __RCC_FLASH_CLK_ENABLE();
    FLASH_SetLatency(FLASH_Latency_3);
    RCC_SysClk_Switch(RCC_SYSCLKSRC_PLL);
    RCC_SystemCoreClockUpdate(64000000);
}

void rccInitHSI(void)
{
    RCC_HSI_Enable(RCC_HSIOSC_DIV6);
}

#endif