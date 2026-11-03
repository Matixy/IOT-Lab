#include "Potentiometer.h"

// constuctor
Potentiometer::Potentiometer(uint8_t pin, float vRef, float adcResolution) : pin(pin), vRef(vRef), adcResolution(adcResolution) {}

void Potentiometer::begin() {
    pinMode(pin, INPUT);
}

uint16_t Potentiometer::getRawValue() const {
    return analogRead(pin);
}

float Potentiometer::getVoltage() const {
    // (Vref / 2^n) * ADC_value
    return (vRef / adcResolution) * (float)getRawValue();
}