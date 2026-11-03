#include <Arduino.h>
#include "Potentiometer.h"

// IDENTIFIERS

#define POT_PIN A0
#define PLOTTER_BAUD 9600

// OBJECTS
Potentiometer potentiometer(POT_PIN); // potentiometer instance

// GLOBAL VARIABLES
uint32_t lastPlotterUpdate = 0;
const uint32_t PLOTTER_UPDATE_INTERVAL = 50; // update plotter every 50 ms


// helper functions
void printPlotterData(uint16_t rawValue, int voltageMicroVolts) {
  Serial.print("ADC_Value: ");
  Serial.print(rawValue);

  // print comma to separate values for serial plotter
  Serial.print(",");

  Serial.print("Voltage_mV: ");
  Serial.println(voltageMicroVolts);
}

void setup() {
  potentiometer.begin(); // initialize potentiometer

  // initialize serial plotter
  Serial.begin(PLOTTER_BAUD);
  while (!Serial) {
    delay(100);
  }
}

void loop() {
  if (millis() - lastPlotterUpdate >= PLOTTER_UPDATE_INTERVAL) {
    
    uint16_t rawValue = potentiometer.getRawValue(); // get raw ADC value
    float voltage = potentiometer.getVoltage(); // get voltage value

    // scale voltage to microvolts for better grid
    int voltageMicroVolts = (int)(voltage * 1000.0f);

    printPlotterData(rawValue, voltageMicroVolts); // print data to serial plotter

    lastPlotterUpdate = millis();
  }
}