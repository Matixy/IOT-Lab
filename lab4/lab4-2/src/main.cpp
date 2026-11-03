#include <Arduino.h>
#include "RgbLed.h"
#include "SerialCli.h"
#include "cmd/CmdRgb.h"
#include "cmd/CmdOff.h"

// IDENTIFIERS

// LED PINS
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

// BUS SPEED
#define BUS_SPEED 9600

// GLOBAL VARIABLES
RgbLed rgbLed(LED_RED, LED_GREEN, LED_BLUE); // red pin 6, green pin 5, blue pin 3

// command objects
CmdRgb cmdRgb(rgbLed);
CmdOff cmdOff(rgbLed);

Command * commands[] = { &cmdRgb, &cmdOff }; // array of command pointers

SerialCli serialCli(commands, sizeof(commands) / sizeof(commands[0]), BUS_SPEED);

void setup() {
  // initialize LED pins
  rgbLed.begin();

  // initialize serial communication
  serialCli.begin();
}

void loop() {
  serialCli.update();
}