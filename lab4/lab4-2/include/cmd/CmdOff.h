#pragma once
#include "Command.h"
#include "RgbLed.h"

class CmdOff : public Command {
    private:
        RgbLed & rgbLed; // reference to the RgbLed object

    public:
        // constructor
        CmdOff(RgbLed & led) : rgbLed(led) {}
        bool matches(const String & input) const override;
        bool execute(const String & input, String & message) override;
};