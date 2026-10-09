# IoT Basics - Lab 2: Digital I/O, Buttons, and PWM
This repository contains solutions for Laboratory 2 of the "Internet of Things Basics" (Podstawy Internetu Rzeczy) course at Wrocław University of Science and Technology (PWr). The lab focuses on configuring digital I/O ports, handling physical push buttons, and controlling an RGB LED using both digital states and PWM (Pulse Width Modulation).

## Hardware Setup
The projects are designed for an Arduino UNO board with the following connections:
*   **RGB LED (Common Cathode):**
    *   Red Anode -> Pin `D6`
    *   Green Anode -> Pin `D5`
    *   Blue Anode -> Pin `D3`
*   **Push Buttons (Normally Open):**
    *   Red Button -> Pin `D2` (Configured as `INPUT_PULLUP`)
    *   Green Button -> Pin `D4` (Configured as `INPUT_PULLUP`)

---

## Programs Overview

### Task 1: Digital I/O & Button Control
This program demonstrates basic digital input reading and output control with software debouncing.
*   **Green Button:** Cycles through the colors of the RGB LED (Red -> Green -> Blue).
*   **Red Button:** Toggles the external RGB LED and the Arduino's built-in LED ON and OFF. 
*   *Key concepts:* `pinMode`, `digitalWrite`, `digitalRead`, `INPUT_PULLUP`, state tracking, debouncing.

### Task 2: PWM Brightness Control
This program uses Pulse Width Modulation (PWM) to control the brightness of a chosen LED (default is Green).
*   **Red Button:** Decreases the brightness of the LED (dims).
*   **Green Button:** Increases the brightness of the LED (brightens).
*   *Key concepts:* `analogWrite`, PWM signals, bounding variable limits (0-255).

### Task 3: RGB Smooth Color Fading
This program creates a smooth cross-fading effect between the primary colors of the RGB LED without any button interaction.
*   The system gradually fades out the current active LED while simultaneously fading in the next one in the array.
*   *Key concepts:* Algorithmic non-blocking delays (or controlled loops), dynamic PWM adjustments, array indexing.

---
---

# Podstawy Internetu Rzeczy - Laboratorium 2: Porty I/O, przyciski i PWM

Repozytorium zawiera kody źródłowe stanowiące rozwiązania zadań z Laboratorium 2 w ramach przedmiotu "Podstawy Internetu Rzeczy" (Politechnika Wrocławska). Ćwiczenia skupiają się na obsłudze cyfrowych portów wejścia/wyjścia, odczycie stanu przycisków oraz sterowaniu diodą RGB za pomocą sygnałów cyfrowych i PWM.

## Połączenia sprzętowe
Programy zostały napisane dla płytki Arduino UNO z wykorzystaniem następujących połączeń:
*   **Dioda RGB (wspólna katoda):**
    *   Anoda czerwona (Red) -> Pin `D6`
    *   Anoda zielona (Green) -> Pin `D5`
    *   Anoda niebieska (Blue) -> Pin `D3`
*   **Przyciski (monostabilne):**
    *   Czerwony przycisk -> Pin `D2` (Wymaga wbudowanego rezystora podciągającego `INPUT_PULLUP`)
    *   Zielony przycisk -> Pin `D4` (Wymaga wbudowanego rezystora podciągającego `INPUT_PULLUP`)

---

## Opis Programów

### Zadanie 1: Konfiguracja, odczyt i sterowanie pinami cyfrowymi
Program demonstruje podstawy odczytu wejść cyfrowych oraz sterowania wyjściami, z uwzględnieniem eliminacji drgań styków (debouncing).
*   **Zielony przycisk:** Zmienia aktualnie świecący kolor w pętli (Czerwony -> Zielony -> Niebieski).
*   **Czerwony przycisk:** Włącza lub wyłącza świecenie diody zewnętrznej oraz wbudowanej diody na płytce Arduino (stan On/Off).
*   *Zastosowane mechanizmy:* `pinMode`, `digitalWrite`, `digitalRead`, `INPUT_PULLUP`, śledzenie stanów zmiennych, proste opóźnienia eliminujące drgania.

### Zadanie 2: Sterowanie jasnością świecenia diody z wykorzystaniem PWM
Program wykorzystuje modulację szerokości impulsu (PWM) do regulacji natężenia światła wybranej diody (domyślnie zielonej).
*   **Czerwony przycisk:** Stopniowo ściemnia diodę (zmniejsza wypełnienie PWM).
*   **Zielony przycisk:** Stopniowo rozjaśnia diodę (zwiększa wypełnienie PWM).
*   *Zastosowane mechanizmy:* Funkcja `analogWrite`, kontrola granic zmiennych (zabezpieczenie przed wyjściem poza zakres 0-255).

### Zadanie 3: Uzyskiwanie kolorów pośrednich w diodzie RGB
Algorytm tworzy efekt płynnego, nieustannego przejścia (fading) pomiędzy składowymi kolorami diody RGB.
*   Dioda aktualnie świecąca powoli przygasa, podczas gdy następna w kolejce równocześnie się rozjaśnia, tworząc w trakcie zmiany kolory pośrednie.
*   *Zastosowane mechanizmy:* Sterowanie PWM w pętli, indeksowanie tablic z pinami diod.