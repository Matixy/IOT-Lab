#include "Menu.h"

Menu::Menu(LiquidCrystal_I2C & lcd, RgbLed & led, uint8_t BRIGHTNESS_STEP) : lcd(lcd), rgbLed(led), BRIGHTNESS_STEP(BRIGHTNESS_STEP) {
    currentMode = Mode::NAVIGATE;
    selectedIndex = OptionsIndexes::TOGGLE_RED;
    topIndex = OptionsIndexes::INFO_PRINT;
}

void Menu::begin() {
    render();
}

void Menu::handleEncoder(int8_t steps) {
    if (steps == 0) {
        return;
    }

    if (currentMode == Mode::NAVIGATE) {
        // moving menu positions 
        int newIndex = selectedIndex + steps;
        selectedIndex = constrain(newIndex, 0, OptionsIndexes::OPTIONS_COUNT - 1);

        // moving screen
        if (selectedIndex == OptionsIndexes::TOGGLE_RED) {
            topIndex = OptionsIndexes::INFO_PRINT;
        } else if (selectedIndex == OptionsIndexes::INFO_PRINT) {
            topIndex = OptionsIndexes::INFO_PRINT;
            selectedIndex = OptionsIndexes::TOGGLE_RED;
        } else if (selectedIndex < topIndex) { // moving up
            topIndex = selectedIndex; 
        } else if (selectedIndex > topIndex + 1) { // moving down
            topIndex = selectedIndex - 1;
        }
    } else if (currentMode == Mode::EDIT) {
        int currentVal = getRgbValue(selectedIndex);
        int newVal = constrain(currentVal + (steps * BRIGHTNESS_STEP), 0, 255);

        setRgbValue(selectedIndex, newVal);
        rgbLed.update();
    }

    render();
}

void Menu::handleSelect() {
    if (currentMode == Mode::NAVIGATE) {
        switch (selectedIndex) {
            case OptionsIndexes::TOGGLE_RED: // turn off/on red 
                if (rgbLed.getRedValue() > 0) {
                    rgbLed.setRedValue(0);
                } else {
                    rgbLed.setRedValue(255);
                }
                rgbLed.update();

                break;

            case OptionsIndexes::TOGGLE_GREEN: // turn off/on green 
                if (rgbLed.getGreenValue() > 0) {
                    rgbLed.setGreenValue(0);
                } else {
                    rgbLed.setGreenValue(255);
                }
                rgbLed.update();

                break;  

            case OptionsIndexes::TOGGLE_BLUE: // turn off/on blue 
                if (rgbLed.getBlueValue() > 0) {
                    rgbLed.setBlueValue(0);
                } else {
                    rgbLed.setBlueValue(255);
                }
                rgbLed.update();
                
                break;
            
            case OptionsIndexes::WRITE_RED: // edit through encoder rgb leds
            case OptionsIndexes::WRITE_GREEN: 
            case OptionsIndexes::WRITE_BLUE:
                currentMode = Mode::EDIT;
                break;

            default:
                break;
        }
    } else {
        currentMode = Mode::NAVIGATE; // button pressed when on edit mode -> change navigate mode
    }

    render();
}

void Menu::render() {
    const char* COLOR_LABELS[3] = {"Red", "Green", "Blue"};
    char lineBuffer[17]; // 16 char in line + \0

    // print 2 menu lines based on topIndex
    for (uint8_t row = 0; row < 2; row++) {
        uint8_t itemIndex = topIndex + row;

        // setting cursor
        char cursor = ' ';
        if (itemIndex == selectedIndex ) {
            cursor = currentMode == Mode::EDIT && selectedIndex != 0 ? '*' : '>';
        }

        switch (itemIndex) {
            // print first line info
            case OptionsIndexes::INFO_PRINT:
                snprintf(lineBuffer, sizeof(lineBuffer), "%-16s", "Menu diod LED:");
                break;

            // prit toggle menu info
            case OptionsIndexes::TOGGLE_RED:
            case OptionsIndexes::TOGGLE_GREEN: 
            case OptionsIndexes::TOGGLE_BLUE: {
                const char* state = getRgbValue(itemIndex) > 0 ? "ON" : "OFF";
                uint8_t colorIndex = (itemIndex - 1) % 3; 

                snprintf(lineBuffer, sizeof(lineBuffer), "[%c]%-7s [%3s]", cursor, COLOR_LABELS[colorIndex], state);
                
                break;
            }
            
            // print write menu info
            case OptionsIndexes::WRITE_RED:
            case OptionsIndexes::WRITE_GREEN: 
            case OptionsIndexes::WRITE_BLUE: {
                uint32_t val = getRgbValue(itemIndex);
                uint8_t colorIndex = (itemIndex - 1) % 3; 

                snprintf(lineBuffer, sizeof(lineBuffer), "[%c]%-7s [%3lu]", cursor, COLOR_LABELS[colorIndex], val);

                break;
            }

            default:
                snprintf(lineBuffer, sizeof(lineBuffer), "%-16s", "");
                break;
        }

        lcd.setCursor(0, row);
        lcd.print(lineBuffer);
    }
}

int Menu::getRgbValue(int index) const {
    switch (OptionsIndexes(index)) {
        case OptionsIndexes::TOGGLE_RED:
        case OptionsIndexes::WRITE_RED:
            return rgbLed.getRedValue();

        case OptionsIndexes::TOGGLE_GREEN: 
        case OptionsIndexes::WRITE_GREEN:
            return rgbLed.getGreenValue();

        case OptionsIndexes::TOGGLE_BLUE:
        case OptionsIndexes::WRITE_BLUE:
            return rgbLed.getBlueValue();

        default:
            return 0;
    }
}

void Menu::setRgbValue(int index, int value) {
    switch (index) {
        case OptionsIndexes::TOGGLE_RED:
        case OptionsIndexes::WRITE_RED:
            rgbLed.setRedValue(value);
            break;

        case OptionsIndexes::TOGGLE_GREEN: 
        case OptionsIndexes::WRITE_GREEN:
            rgbLed.setGreenValue(value);
            break;

        case OptionsIndexes::TOGGLE_BLUE:
        case OptionsIndexes::WRITE_BLUE:
            rgbLed.setBlueValue(value);
            break;

        default:
            break;
    }
}