#pragma once
#include <Arduino.h>

class Encoder
{
private:
    //ATTRIBUTES
    // constatnts variabbles
    const uint8_t pinA;
    const uint8_t pinB;
    const uint32_t debounceDeleay;

    volatile int8_t step; // represents encoder steps (+1 rotation to the right, -1 to the left, 0 no rotation)
    volatile uint8_t lastPinA;
    volatile uint32_t lastDebounceTime;

    static Encoder* instance;

    // FUNCTIONS
    void handleInterrupt();


public:
    //METHODS
    // constructor
    Encoder(uint8_t assignedPinA, uint8_t assignedPinB, uint32_t debounceDeleay);

    void begin();

    void static onInterrupt();

    // GETTERS & SETTERS
    int8_t getStep();
};