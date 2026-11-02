#include "RgbLed.h"

// Constructor
RgbLed::RgbLed(uint8_t firstPin, uint8_t secondPin, uint8_t thirdPin) : pinsSequence{firstPin, secondPin, thirdPin} {
    colorIndex = 0;
}

// method to initialize LED pins
void RgbLed::begin() {
    for (int i = 0; i < 3; i++) {
        pinMode(pinsSequence[i], OUTPUT);
        digitalWrite(pinsSequence[i], LOW);
    }

    digitalWrite(pinsSequence[0], HIGH); // set first color to high
}

// method to cycle through colors
void RgbLed::nextColor() {
    digitalWrite(pinsSequence[colorIndex], LOW); // turn off current color
    colorIndex = (colorIndex + 1) % 3; // move to next color
    digitalWrite(pinsSequence[colorIndex], HIGH); // turn on next color
}