#include "cmd/CmdOff.h"

bool CmdOff::matches(const String & input) const {
    return input == "off";
}

bool CmdOff::execute(const String & input, String & message) {
    rgbLed.setColor(0, 0, 0); // turn off the LED
    message = "LED turned off."; // return confirmation message
    return true;
}
