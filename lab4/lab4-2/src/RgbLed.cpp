#include "RgbLed.h"

// Constructor
RgbLed::RgbLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) : pinRed(redPin), pinGreen(greenPin), pinBlue(bluePin) {
}

// method to initialize LED pins
void RgbLed::begin() {
    // set pin modes for each LED pin
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen, OUTPUT);
    pinMode(pinBlue, OUTPUT);

    setColor(0, 0, 0); // turn off all colors initially
}

// method to set the color of the RGB LED with PWM values for each color
void RgbLed::setColor(uint8_t redValue, uint8_t greenValue, uint8_t blueValue) {
    analogWrite(pinRed, redValue);
    analogWrite(pinGreen, greenValue);
    analogWrite(pinBlue, blueValue);
}