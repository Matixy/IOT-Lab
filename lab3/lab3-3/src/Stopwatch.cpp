#include "Stopwatch.h"

// constructor
Stopwatch::Stopwatch() {
    isRunning = false;
    miliSeconds = 0;
    seconds = 0;
    minutes=0;
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
    miliSeconds = 0;
    seconds = 0;
    minutes = 0;
}

// method to update the stopwatch
bool Stopwatch::update() {
    if (isRunning) {
        bool hasChanged = false;

        // if 100 miliseconds has passed change attributes
        while (millis() - lastTickTime >= 10) {
            miliSeconds += 1;

            if (miliSeconds >= 100) {
                seconds++;
                miliSeconds -= 100;

                if (seconds >= 60) {
                    minutes++;
                    seconds = 0;
                }
            }

            lastTickTime += 10;
            hasChanged = true;
        }

        return hasChanged;
    }

    return false; // return false to indicate that second has not passed
}

// getter for miliseconds
uint32_t Stopwatch::getMiliseconds() const {
    return miliSeconds;
}

// getter for seconds
uint32_t Stopwatch::getSeconds() const {
    return seconds;
}

// getter for minutes
uint32_t Stopwatch::getMinutes() const {
    return minutes;
}

// getter for isRunning
bool Stopwatch::getIsRunning() const {
    return isRunning;
}