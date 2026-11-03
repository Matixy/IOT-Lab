#pragma once
#include <Arduino.h>

class Potentiometer {
    private:
        // attributes 
        // constants 
        const uint8_t pin;
        const float vRef; // reference voltage
        const float adcResolution; // ADC resolution

    public:
        // methods
        Potentiometer(uint8_t pin, float vRef = 5.0f, float adcResolution = 1024.0f);

        void begin();

        uint16_t getRawValue() const; // get raw ADC value
        float getVoltage() const; // get voltage value
};