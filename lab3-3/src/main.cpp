#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Button.h"
#include "Stopwatch.h"

// IDENTIFIERS

// BUTTON PINS
#define RED_BUTTON 2
#define GREEN_BUTTON 4

// GLOBAL VARIABLES
Button redButton(RED_BUTTON, 50); // pin 2, debounce delay 50ms
Button greenButton(GREEN_BUTTON, 50); // pin 4, debounce delay 50ms
Stopwatch stopwatch; // stopwatch instance
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD instance with I2C address 0x27 and size 16x2

// function updating display
void updateDisplay() {
    lcd.setCursor(0, 1);
    lcd.print("Czas: ");
    lcd.print(stopwatch.getSeconds());

    lcd.print(" s      "); // clear any remaining characters on the line

    // display stopwatch state
    lcd.setCursor(14, 1);
    if (stopwatch.getIsRunning()) {
        lcd.print(" >");
    } else {
        lcd.print("||");
    }
}

void setup() {
    // initialize buttons
    redButton.begin();
    greenButton.begin();

    // initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Stoper");

    updateDisplay();
}

void loop() {
    // collect button states
    redButton.update();
    greenButton.update();

    // toggle stopwatch if green button is released
    if (greenButton.wasReleased()) {
        stopwatch.toggle();
        updateDisplay();
    }

    // reset stopwatch if red button is released
    if (redButton.wasReleased()) {
        stopwatch.stop();
        stopwatch.reset();
        updateDisplay();
    }

    // update stopwatch and display if a second has passed
    if (stopwatch.update()) {
        updateDisplay();
    }
}