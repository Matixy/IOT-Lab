#include <Arduino.h>
#include "AsyncLed.h"

// IDENTIFIERS

// LED PINS
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

// BUTTON PINS
#define RED_BUTTON 2

// GLOBAL VARIABLES
AsyncLed redLed(LED_RED, 900); // red led, blink interval 0.9s
AsyncLed greenLed(LED_GREEN, 1000); // green led, blink interval 1s
AsyncLed blueLed(LED_BLUE, 1100); // blue led, blink interval 1.1s

void setup() {
  // initialize leds
  redLed.begin();
  greenLed.begin();
  blueLed.begin();
}

void loop() {
  // update button state 
  redLed.update();
  greenLed.update();
  blueLed.update();
}