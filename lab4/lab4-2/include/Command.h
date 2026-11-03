#pragma once
#include <Arduino.h>

class Command {
    public:
        virtual ~Command() {};

        // method to check if the command matches the given input
        virtual bool matches(const String & input) const = 0;

        // method to execute the command with the given input
        virtual bool execute(const String & input, String & message) = 0;
};