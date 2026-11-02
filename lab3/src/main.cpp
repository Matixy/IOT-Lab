#include <Arduino.h>
#include "Button.h"
#include "RgbLed.h"

// IDENTIFIERS

// LED PINS
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

// BUTTON PINS
#define RED_BUTTON 2
#define GREEN_BUTTON 4

// GLOBAL VARIABLES
Button redButton(RED_BUTTON, 50); // pin 2, debounce delay 50ms
Button greenButton(GREEN_BUTTON, 50); // pin 4, debounce delay 50ms
RgbLed rgbLed(LED_RED, LED_GREEN, LED_BLUE); // red pin 6, green pin 5, blue pin 3

void setup() {
    // initialize LED and button pins
    redButton.begin();
    greenButton.begin();
    rgbLed.begin();
}

void loop() {
    redButton.update();
    greenButton.update();

    if (redButton.wasReleased() || greenButton.wasReleased()) {
        rgbLed.nextColor();
    }
}