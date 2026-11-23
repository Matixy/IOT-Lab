#include "Encoder.h"
#include <util/atomic.h>

// initialaize static variable
Encoder* Encoder::instance = nullptr;

Encoder::Encoder(uint8_t assignedPinA, uint8_t assignedPinB, uint32_t debounceDeleay) : pinA(assignedPinA), pinB(assignedPinB), debounceDeleay(debounceDeleay) {
    // Initialize encoder state variables
    step = 0;
    lastPinA = HIGH;
    lastDebounceTime = 0;
    instance = this;
}

void Encoder::begin() {
    // initialize encoder pins 
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
    lastPinA = digitalRead(pinA);

    // configuration external interrupt
    PCICR |= (1 << PCIE1);
    PCMSK1 |= (1 << PCINT10);
}

void Encoder::handleInterrupt() {
    uint8_t currentA = digitalRead(pinA);
    uint8_t currentB = digitalRead(pinB);
    uint32_t currentTs = millis();

    // detect pinA HIGH-> LOW move 
    if (currentA == LOW && lastPinA == HIGH && currentTs - lastDebounceTime > debounceDeleay) {
        if (currentB == HIGH) {
            step ++; // right
        } else {
            step --; // left
        }
        lastDebounceTime = currentTs;
        
    }
    
    lastPinA = currentA;

}

void Encoder::onInterrupt() {
    if (instance != nullptr) {
        instance->handleInterrupt();
    }
}

// GETTERS & SETTERS 
int8_t Encoder::getStep() {
    int8_t stepValue = 0;
    

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        stepValue = step;
        step = 0;
    }
    
    return stepValue;
}

ISR(PCINT1_vect) {
    Encoder::onInterrupt();
}