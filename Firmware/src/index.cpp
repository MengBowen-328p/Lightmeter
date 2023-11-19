//
// Created by 15216 on 2023/11/19.
//

#include "index.h"

uint8_t INDEX::getISOIndex(void)
{
    iso_index = EEPROM.read(ISOINDEX_ADDR);
    return iso_index;
}

uint8_t INDEX::getApertureIndex(void)
{
    aperture_index = EEPROM.read(APERATUREINDEX_ADDR);
    return aperture_index;
}

uint8_t INDEX::getTexpIndex(void)
{
    texp_index = EEPROM.read(TEXPINDEX_ADDR);
    return texp_index;
}

uint8_t INDEX::getModelIndex(void)
{
    mode_index = EEPROM.read(METERINGMODE_ADDR);
    return mode_index;
}

uint8_t INDEX::getMeteringMode(void)
{
    metering_mode = EEPROM.read(METERINGMODE_ADDR);
    return metering_mode;
}

uint8_t INDEX::getNDIndex(void)
{
    nd_index = EEPROM.read(NDINDEX_ADDR);
    return nd_index;
}

void INDEX::setISOIndex(uint8_t isoindex)
{
    this->iso_index = isoindex;
}

void INDEX::setApertureIndex(uint8_t apertureindex)
{
    this->aperture_index = apertureindex;
}

void INDEX::setTexpIndex(uint8_t texpindex)
{
    this->texp_index = texpindex;
}

void INDEX::setModelIndex(uint8_t modelindex)
{
    this->mode_index = modelindex;
}

void INDEX::setMeteringMode(uint8_t meteringmode)
{
    this->metering_mode = meteringmode;
}

void INDEX::setNDIndex(uint8_t ndindex)
{
    this->nd_index = ndindex;
}







