#pragma once
#include <Arduino.h>

class RgbLed
{
    private:
        //ATTRIBUTES
        // constant attributes for each LED pin
        const uint8_t pinsSequence[3]; // array which stores pin in order of switching colors
        uint8_t colorIndex;

    public:
        //METHODS
        // constructor
        RgbLed(uint8_t firstPin, uint8_t secondPin, uint8_t thirdPin);

        void begin();
        void nextColor();
};