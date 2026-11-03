#include <Arduino.h>
#include "Button.h"

// BUTTON PINS
#define RED_BUTTON 2
#define GREEN_BUTTON 4

// bus speed 
#define SERIAL_BAUD 115200

// GLOBAL VARIABLES
// buttons
Button redButton(RED_BUTTON, 50); // pin 2, debounce delay 50ms
Button greenButton(GREEN_BUTTON, 50); // pin 4, debounce delay 50ms

// rate limiting variables
uint32_t lastPrintTime = 0;
const uint32_t printInterval = 50; // 50 ms

void setup() {
  // initilazie buttons
  redButton.begin();
  greenButton.begin();

  // setup serial communication
  Serial.begin(SERIAL_BAUD); // max standard speed

  while (!Serial) {
    delay(10); // wait for serial port to connect
  }
}

void loop() {
  // update button states
  redButton.update();
  greenButton.update();

  // sending data to serial plotter 
  if (millis() - lastPrintTime >= printInterval) {
    // red button state
    Serial.print("Red: ");
    Serial.print(redButton.isPressed() ? "1" : "0");
    
    // ',' is used as variable separator in plotter 
    Serial.print(",");

    // green button state
    Serial.print("Green: ");
    Serial.println(greenButton.isPressed() ? "1" : "0");

    lastPrintTime += printInterval;
  }
}