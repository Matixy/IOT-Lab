#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RgbLed.h"
#include "Button.h"
#include "Encoder.h"
#include "Menu.h"

// LED PINS
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

// ENCODER PINS
#define ENCODER1 A2
#define ENCODER2 A3

#define RED_BUTTON 2
#define GREEN_BUTTON 4

// GLOBAL VARIABLES
Button greenButton(GREEN_BUTTON, 100);       // pin 4, debounce delay 50ms
LiquidCrystal_I2C lcd(0x27, 16, 2);          // LCD instance with I2C address 0x27 and 16 columns, 2 rows
RgbLed rgbLed(LED_RED, LED_GREEN, LED_BLUE); // red pin 6, green pin 5, blue pin 3
Encoder encoder(ENCODER1, ENCODER2, 20);     // encoder with debounce delay 20 ms
Menu menu(lcd, rgbLed, 15); // menu with brightness step = 15

void setup()
{
  rgbLed.begin();
  greenButton.begin();
  encoder.begin();

  lcd.init();
  lcd.backlight();

  menu.begin();
}

void loop() {
  greenButton.update();

  // if encoder moving handle encoder events in menu class
  int8_t steps = encoder.getStep();
  if (steps != 0) {
    menu.handleEncoder(steps);
  }

  // if grenn button was pressed handle encoder events in menu class
  if (greenButton.wasReleased()) {
    menu.handleSelect();
  }

}