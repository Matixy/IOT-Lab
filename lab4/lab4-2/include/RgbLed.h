#pragma once
#include <Arduino.h>

class RgbLed
{
    private:
        //ATTRIBUTES
        // constant attributes for each LED pin
        const uint8_t pinRed;
        const uint8_t pinGreen;
        const uint8_t pinBlue;

    public:
        //METHODS
        // constructor
        RgbLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);

        void begin();
        void setColor(uint8_t redValue, uint8_t greenValue, uint8_t blueValue);
};