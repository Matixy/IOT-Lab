#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Potentiometer.h"

// IDENTIFIERS

// PINS
#define POT_PIN A0

// OBJECTS
Potentiometer potentiometer(POT_PIN); // potentiometer instance
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD instance with I2C address 0x27 and 16 columns, 2 rows

// GLOBAL VARIABLES
uint16_t rawValue = 0; // raw ADC value
uint16_t lastLcdUpdate = 0;
const uint32_t LCD_UPDATE_INTERVAL = 100; // update LCD every 100 ms

// helper functions
void printLcdTemplate() {
  lcd.setCursor(0, 0);
  lcd.print("ADC value: ");

  lcd.setCursor(0, 1);
  lcd.print("VOLTAGE: ");
}

void printAdcToLcd(uint16_t adcValue) {
  lcd.setCursor(11, 0);
  lcd.print(adcValue);
  
  // clear any remaining characters from previous values
  if (adcValue < 1000) lcd.print(" "); 
  if (adcValue < 100)  lcd.print(" ");
  if (adcValue < 10)   lcd.print(" ");
}

void printVoltageToLcd(float voltage) {
  lcd.setCursor(11, 1);
  lcd.print(voltage, 2); // print voltage with 2 decimal places
  lcd.print("V");
}

void setup() {
  potentiometer.begin(); // initialize potentiometer

  // initialize LCD
  lcd.init();
  lcd.backlight();

  printLcdTemplate();
}

void loop() {
  // read potentiometer value 
  uint16_t currentRawValue = potentiometer.getRawValue();

  // check if the value has changed and if enough time has passed since the last update
  if (
    (currentRawValue != rawValue) &&
    (millis() - lastLcdUpdate >= LCD_UPDATE_INTERVAL)
  ) {

    // print the new values to the LCD
    printAdcToLcd(currentRawValue);
    printVoltageToLcd(potentiometer.getVoltage());


    // update program state
    rawValue = currentRawValue;
    lastLcdUpdate = millis();
  }
}