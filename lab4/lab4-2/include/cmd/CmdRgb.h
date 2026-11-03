#pragma once
#include "Command.h"
#include "RgbLed.h"

class CmdRgb : public Command {
    private:
        // atributes
        RgbLed & rgbLed; // reference to the RgbLed object
        void setReturnMessage(const uint8_t redValue, const uint8_t greenValue, const uint8_t blueValue, String & message); // method to print RGB set message

    public:
        // constructor
        CmdRgb(RgbLed & led) : rgbLed(led) {}
        bool matches(const String & input) const override;
        bool execute(const String & input, String & message) override;
};