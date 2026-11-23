#include "RgbLed.h"

// Constructor
RgbLed::RgbLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) : pinRed(redPin), pinGreen(greenPin), pinBlue(bluePin) {
    // turn off all colors initally
    redValue = 0;
    greenValue = 0;
    blueValue = 0;
}

// method to initialize LED pins
void RgbLed::begin() {
    // set pin modes for each LED pin
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen, OUTPUT);
    pinMode(pinBlue, OUTPUT);

    update(); // turn off all colors initially
}

// method to set the color of the RGB LED with PWM values for each color
void RgbLed::update() {
    analogWrite(pinRed, redValue);
    analogWrite(pinGreen, greenValue);
    analogWrite(pinBlue, blueValue);
}

uint8_t RgbLed::getRedValue() const {
    return redValue;
}

void RgbLed::setRedValue(uint8_t value) {
    redValue = constrain(value, 0, 255);;
}

uint8_t RgbLed::getGreenValue() const {
    return greenValue;
}

void RgbLed::setGreenValue(uint8_t value) {
    greenValue = constrain(value, 0, 255);;
}

uint8_t RgbLed::getBlueValue() const {
    return blueValue;
}

void RgbLed::setBlueValue(uint8_t value) {
    blueValue = constrain(value, 0, 255);
}