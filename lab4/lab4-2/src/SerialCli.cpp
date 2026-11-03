#include "SerialCli.h"

// constructor
SerialCli::SerialCli(Command ** commands, uint8_t commandCount, uint32_t baudRate) : comands(commands), commandCount(commandCount), baudRate(baudRate) {}

// PRIVATE METHODS

// method to print startup message
void SerialCli::printStartupMessage() {
    Serial.println("RGB LED Control Initialized");
    Serial.println("Enter RGB values (0-255) separated by spaces: 'rgb <red> <green> <blue>'");
    Serial.println("Example: rgb 255 0 0 for red, rgb 0 255 0 for green, rgb 0 0 255 for blue");
    Serial.println("Enter 'off' to turn off the LED.");
}

// method to print success message
void SerialCli::printSuccessMessage(const String & message) {
    Serial.print("[SUCCESS] ");
    Serial.println(message);
}

// method to print error message
void SerialCli::printErrorMessage(const String & message) {
    Serial.print("[ERROR] ");
    Serial.println(message);
}

// method to process input
String SerialCli::processInput(const String & input) {
    String trimmedInput = input;
    trimmedInput.trim(); // remove leading and trailing whitespace
    trimmedInput.toLowerCase(); // convert to lowercase for case-insensitive comparison

    return trimmedInput;
}

// PUBLIC METHODS

// method to initialize serial communication
void SerialCli::begin() {
    Serial.begin(baudRate);
    while (!Serial) {
        delay(10); // wait for serial port to connect
    }

    printStartupMessage(); // print initialization message
}

// method to handle serial input
void SerialCli::update() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n'); // read input until newline

        String processedInput = processInput(input); // preprocess input

        bool foundCommand = false;
        for (uint8_t i = 0; i < commandCount; i++) {
            if (comands[i]->matches(processedInput)) {
                String resultMessage;

                bool success = comands[i]->execute(processedInput, resultMessage); // execute command

                if (success) {
                    printSuccessMessage(resultMessage); // print confirmation message
                } else {
                    printErrorMessage(resultMessage); // print error message
                }

                foundCommand = true;
                break; // exit loop
            }
        }

        if (!foundCommand) {
            printErrorMessage("Invalid command.");
        }
    }
}