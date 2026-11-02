#pragma once
#include <Arduino.h>

class Stopwatch
{
    private:
        //ATTRIBUTES
        bool isRunning;
        uint32_t seconds; // actual seconds counted
        uint32_t lastTickTime; // last time the stopwatch was updated

    public:
        //METHODS
        // constructor
        Stopwatch();

        void toggle();
        void stop();
        void reset();
        bool update();

        // GETTERS & SETTERS
        uint32_t getSeconds() const;
        bool getIsRunning() const;
};