#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "RgbLed.h"

class Menu
{
private:
    // private enum for menu state
    enum class Mode : uint8_t { 
        NAVIGATE,
        EDIT
    };

    enum OptionsIndexes {
        INFO_PRINT = 0,
        TOGGLE_RED = 1,
        TOGGLE_GREEN = 2,
        TOGGLE_BLUE = 3,
        WRITE_RED = 4,
        WRITE_GREEN = 5,
        WRITE_BLUE = 6,
        OPTIONS_COUNT = 7 // 
    };

    //ATTRIBUTES
    const uint8_t BRIGHTNESS_STEP;

    // external attributes
    LiquidCrystal_I2C & lcd;
    RgbLed & rgbLed;

    // lcd states attributes
    Mode currentMode;
    int selectedIndex; // actual cursor lcd position
    int topIndex; // top index row pritet in lcd screen

    void render();
    int getRgbValue(int index) const;
    void setRgbValue(int index, int value);

public:
    //METHODS
    // constructor
    Menu(LiquidCrystal_I2C & lcd, RgbLed & led, uint8_t BRIGHTNESS_STEP);

    void begin();
    void handleEncoder(int8_t steps);
    void handleSelect();

};