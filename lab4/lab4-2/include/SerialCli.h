#pragma once
#include <Arduino.h>
#include "RgbLed.h"
#include "Command.h"

class SerialCli {
    private:
        // attributes
        // static attributes
        const static uint32_t DEFAULT_BAUD_RATE = 9600; // default baud rate

        // atributes
        uint32_t baudRate; // baud rate for serial communication
        Command ** comands; // array of command pointers
        uint8_t commandCount; // number of commands

        // methods
        void printStartupMessage();
        void printSuccessMessage(const String & message);
        void printErrorMessage(const String & message);
        String processInput(const String & input);
        
    public:
        // methods
        //constructor
        SerialCli(Command ** commands, uint8_t commandCount, uint32_t baudRate = DEFAULT_BAUD_RATE);

        void begin();
        void update();
};