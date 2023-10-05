#include "oled.h"

void hi2cWriteCMD(uint8_t data) 
{
    uint8_t i2c_state = 0;
    I2C_AcknowledgeConfig(CW_I2C2, ENABLE);
    I2C_GenerateSTART(CW_I2C2, ENABLE);
    i2c_state = I2C_GetState(CW_I2C2);
    switch (i2c_state)
    {   
        case 0x08:
        {
            I2C_GenerateSTART(CW_I2C2,DISABLE);
            I2C_Send7bitAddress(CW_I2C2, OLED_ADDR, I2C_Direction_Transmitter);
            break;
        }
        case 0x18:
        {
            I2C_SendData(CW_I2C2,CMD_RES);
            break;
        }
        case 0x28:
        {
            I2C_SendData(CW_I2C2,data);
            break;
        }
        default:
        {
            break;
        }
    }
    I2C_GenerateSTOP(CW_I2C2, ENABLE);
}

void hi2cWriteData(uint8_t* data) 
{
    uint8_t i2c_state = 0;
    uint8_t i = 0;
    I2C_AcknowledgeConfig(CW_I2C2, ENABLE);
    I2C_GenerateSTART(CW_I2C2, ENABLE);
    i2c_state = I2C_GetState(CW_I2C2);
    switch (i2c_state)
    {   
        case 0x08:
        {
            I2C_GenerateSTART(CW_I2C2,DISABLE);
            I2C_Send7bitAddress(CW_I2C2, OLED_ADDR, I2C_Direction_Transmitter);
            break;
        }
        case 0x18:
        {
            I2C_SendData(CW_I2C2,DATA_RES);
            break;
        }
        case 0x28:
        {
            I2C_SendData(CW_I2C2,data[i++]);
            break;
        }
        default:
        {
            break;
        }
    }
    I2C_GenerateSTOP(CW_I2C2, ENABLE);
}

void oledInit(void)
{
    //GPIO Init
    GPIO_InitTypeDef GPIO_InitStructre;
    PB13_AFx_I2C2SCL();
    PB14_AFx_I2C2SDA();
    PB11_AFx_I2C1SDA();
    GPIO_InitStructre.Pins  = OLED_SDA_PIN | OLED_SCL_PIN;
    GPIO_InitStructre.Mode  = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStructre.Speed = GPIO_SPEED_HIGH;
    GPIO_Init(OLED_I2C_GPIOPort, &GPIO_InitStructre);

    //I2C Init
    I2C_InitTypeDef I2C_InitStructre;
    I2C_InitStructre.I2C_BaudEn = ENABLE;
    I2C_InitStructre.I2C_Baud = 0x08;
    I2C_InitStructre.I2C_FLT = DISABLE;
    I2C_InitStructre.I2C_AA = DISABLE;
    I2C2_DeInit();
    I2C_Master_Init(CW_I2C2,&I2C_InitStructre);

    //OLED Init
    hi2cWriteCMD(0xAE);

}