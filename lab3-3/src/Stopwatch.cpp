#include "Stopwatch.h"

// constructor
Stopwatch::Stopwatch() {
    isRunning = false;
    seconds = 0;
    lastTickTime = 0;
}

// method to toggle the stopwatch state
void Stopwatch::toggle() {
    isRunning = !isRunning;

    // if stopwatch is started reset last tick time to current time
    if (isRunning) {
        lastTickTime = millis();
    }
}

// method to stop the stopwatch
void Stopwatch::stop() {
    isRunning = false;
}

// method to reset the stopwatch
void Stopwatch::reset() {
    seconds = 0;
}

// method to update the stopwatch
bool Stopwatch::update() {
    if (isRunning) {
        // if one second has passed 
        if (millis() - lastTickTime >= 1000) {
            seconds++;
            lastTickTime += 1000; // update last tick time
            return true; // return true to indicate that a second has passed
        }
    }

    return false; // return false to indicate that second has not passed
}

// getter for seconds
uint32_t Stopwatch::getSeconds() const {
    return seconds;
}

// getter for isRunning
bool Stopwatch::getIsRunning() const {
    return isRunning;
}