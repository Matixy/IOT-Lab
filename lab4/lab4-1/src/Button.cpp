#include "Button.h"

// Constructor
Button::Button(uint8_t assignedPin, uint32_t delayMs) : pin(assignedPin), debounceDelay(delayMs) {
    lastDebounceTime = 0;
    buttonState = HIGH;
    lastReading = HIGH;
    releasedFlag = false;
}

// method to initialize button pin
void Button::begin() {
    pinMode(pin, INPUT_PULLUP);
}

// method to update button state and check for release
void Button::update() {
    releasedFlag = false;
    bool currentReading = digitalRead(pin);

    if (currentReading != lastReading) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (currentReading != buttonState) {
            buttonState = currentReading;

            if (buttonState == HIGH) {
                releasedFlag = true;
            }
        }
    }

    lastReading = currentReading;
}

// getter for releasedFlag
bool Button::wasReleased() const {
    return releasedFlag;
}

// getter for buttonState
bool Button::isPressed() const {
    return buttonState == LOW; // LOW = pressed in INPUT_PULLUP configuration
}