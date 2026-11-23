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

        // 
        uint8_t redValue;
        uint8_t greenValue;
        uint8_t blueValue;

    public:
        //METHODS
        // constructor
        RgbLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);

        void begin();
        void update();

        // getters & setters
        uint8_t getRedValue () const;
        void setRedValue (uint8_t value);

        uint8_t getGreenValue () const;
        void setGreenValue (uint8_t value);

        uint8_t getBlueValue () const;
        void setBlueValue (uint8_t value);
};