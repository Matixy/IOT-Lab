#pragma once
#include <Arduino.h>

class Button
{
private:
    //ATTRIBUTES
    // constants attributes for each button
    const uint8_t pin;
    const uint32_t debounceDelay;

    uint32_t lastDebounceTime;

    bool buttonState;
    bool lastReading;
    bool releasedFlag;

public:
    //METHODS
    // constructor
    Button(uint8_t assignedPin, uint32_t delayMs = 50);

    void begin();
    void update();

    // GETTERS & SETTERS
    bool wasReleased() const;
};
