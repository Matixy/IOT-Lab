#pragma once
#include <Arduino.h>

class AsyncLed {
    private:
        // ATTRIBUTES
        // constants atributes for each led
        const uint8_t pin;
        const uint32_t blinkInterval;

        uint32_t lastToggleTime;
        bool ledState;

    public:
        //METHODS
        // constructor
        AsyncLed(uint8_t assignedPin, uint32_t intervalMs);

        void begin();
        void update();

};