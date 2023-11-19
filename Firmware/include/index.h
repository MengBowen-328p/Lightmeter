//
// Created by 15216 on 2023/11/19.
//

#ifndef FIRMWARE_INDEX_H
#define FIRMWARE_INDEX_H

#include <Arduino.h>
#include <EEPROM.h>

#define ISOINDEX_ADDR           1
#define APERATUREINDEX_ADDR     2
#define MODEINDEX_ADDR          3
#define TEXPINDEX_ADDR          4
#define METERINGMODE_ADDR       5
#define NDINDEX_ADDR            6

class INDEX
{
private:
    uint8_t iso_index;
    uint8_t aperture_index;
    uint8_t texp_index;
    uint8_t mode_index;
    uint8_t metering_mode;
    uint8_t nd_index;
public:
    uint8_t getISOIndex(void);

    uint8_t getApertureIndex(void);

    uint8_t getTexpIndex(void);

    uint8_t getModelIndex(void);

    uint8_t getMeteringMode(void);

    uint8_t getNDIndex(void);

    void setISOIndex(uint8_t isoindex);

    void setApertureIndex(uint8_t apertureindex);

    void setTexpIndex(uint8_t texpindex);

    void setModelIndex(uint8_t modelindex);

    void setMeteringMode(uint8_t meteringmode);

    void setNDIndex(uint8_t ndindex);
};


#endif //FIRMWARE_INDEX_H
