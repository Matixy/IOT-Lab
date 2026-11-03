#include "cmd/CmdRgb.h"

// override virutal methods
bool CmdRgb::matches(const String & input) const {
    return input.startsWith("rgb ");
}

bool CmdRgb::execute(const String & input, String & message) {
    int redValue, greenValue, blueValue;
    int parsedValues = sscanf(input.c_str(), "rgb %d %d %d", &redValue, &greenValue, &blueValue);

    if (parsedValues == 3) {
        // secure the values are between [0,255]
        redValue = constrain(redValue, 0, 255);
        greenValue = constrain(greenValue, 0, 255);
        blueValue = constrain(blueValue, 0, 255);

        rgbLed.setColor(redValue, greenValue, blueValue); // set color
        setReturnMessage(redValue, greenValue, blueValue, message); // set confirmation message
    } else {
        message = "Invalid input. Please enter RGB values (0-255) in the format: 'rgb <red> <green> <blue>'"; // return error message

        return false;
    }

    return true;
}

// private methods

// method to print RGB set message
void CmdRgb::setReturnMessage(const uint8_t redValue, const uint8_t greenValue, const uint8_t blueValue, String & message) {
    message = "LED color set to: R=" + String(redValue) + ", G=" + String(greenValue) + ", B=" + String(blueValue);
}