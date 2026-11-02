#include <Arduino.h>
#include "AsyncLed.h"
#include "Button.h"

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

// red button for test
Button redButton(RED_BUTTON, 50); // pin 2, debounce delay 50ms

void setup() {
  // initialize leds
  redLed.begin();
  greenLed.begin();
  blueLed.begin();

  // initialize button
  redButton.begin();
  Serial.begin(9600); // initialize serial communication for debugging
}

void loop() {
  // update button state 
  redLed.update();
  greenLed.update();
  blueLed.update();

  // test for multithreading
  redButton.update();
  if (redButton.wasReleased()) {
    Serial.println("Red button was released");
  }
}