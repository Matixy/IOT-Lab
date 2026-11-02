#include "AsyncLed.h"

// constructor
AsyncLed::AsyncLed(uint8_t assignedPin, uint32_t intervalMs) : pin(assignedPin), blinkInterval(intervalMs) {
    lastToggleTime = 0;
    ledState = LOW; // led is off initially
}

// method to initialize the led pin
void AsyncLed::begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, ledState);
}

// method to update the led state based on the blink interval
void AsyncLed::update() {
    // check if blink interval has passed for this diode
    if (millis() - lastToggleTime >= blinkInterval) {
        ledState = !ledState; // toggle the led state
        digitalWrite(pin, ledState);

        lastToggleTime += blinkInterval; // update the last toggle time
    }
}