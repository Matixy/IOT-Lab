# IoT Basics - Lab 3: Debouncing, Concurrency, and LCD
This repository contains solutions for Laboratory 3 of the "Internet of Things Basics" (Podstawy Internetu Rzeczy) course at Wrocław University of Science and Technology (PWr). The lab focuses on software debouncing of mechanical buttons, non-blocking multitasking using the `millis()` function, and driving a 16x2 LCD display over the I2C bus. 

The code in this laboratory has been heavily refactored to use **Object-Oriented Programming (OOP)** in C++ (custom classes: `Button`, `RgbLed`, `AsyncLed`, `Stopwatch`) for better modularity and reusability, typical for PlatformIO projects.

## Hardware Setup
The projects are designed for an Arduino UNO board with the following connections:
*   **RGB LED (Common Cathode):**
    *   Red Anode -> Pin `D6`
    *   Green Anode -> Pin `D5`
    *   Blue Anode -> Pin `D3`
*   **Push Buttons (Normally Open):**
    *   Red Button -> Pin `D2` (Configured as `INPUT_PULLUP`)
    *   Green Button -> Pin `D4` (Configured as `INPUT_PULLUP`)
*   **LCD Display (16x2) with I2C Adapter:**
    *   SDA -> `A4` (or dedicated SDA pin)
    *   SCL -> `A5` (or dedicated SCL pin)
    *   VCC -> `5V`
    *   GND -> `GND`
    *   *I2C Address:* `0x27`

---

## Programs Overview

### Task 1: Software Debouncing & RGB Cycle
This program demonstrates how to eliminate mechanical contact bounce (debouncing) using a non-blocking `millis()` approach encapsulated in a custom `Button` class.
*   **Both Buttons (Red & Green):** Trigger the `RgbLed` to transition to its next color (Red -> Green -> Blue).
*   *Key concepts:* Class encapsulation, state machines, hardware debouncing theory vs. software implementation, falling edge detection (`wasReleased()`).

### Task 2: Concurrency / Multitasking
This program proves that a single-core microcontroller can run multiple tasks simultaneously without mutual blocking, completely eliminating the `delay()` function.
*   **LEDs:** The Red, Green, and Blue LEDs blink at entirely different intervals (0.9s, 1.0s, and 1.1s respectively) managed by the `AsyncLed` class.
*   **Button:** The Red button can be pressed at any time to output a message to the Serial Monitor (9600 baud rate) without interrupting the LEDs' blinking rhythms.
*   *Key concepts:* `millis()` time-tracking, non-blocking code, asynchronous execution.

### Task 3: Electronic Stopwatch (LCD)
This program implements a fully functional stopwatch with a hardware display, updating dynamically without clearing the whole screen to prevent flickering.
*   **Green Button:** Toggles the stopwatch state (Start / Pause).
*   **Red Button:** Stops the stopwatch and resets the counted time to zero.
*   **LCD:** Displays "Stoper" on the top line, the elapsed time in seconds, and the current state indicator (`>` for running, `||` for paused).
*   *Key concepts:* I2C bus communication, `LiquidCrystal_I2C` library, partial screen updates, precise time accumulation (`Stopwatch` class).

---
---

# Podstawy Internetu Rzeczy - Laboratorium 3: Eliminacja drgań styków, wielozadaniowość, wyświetlacz LCD

Repozytorium zawiera kody źródłowe stanowiące rozwiązania zadań z Laboratorium 3 w ramach przedmiotu "Podstawy Internetu Rzeczy" (Politechnika Wrocławska). Ćwiczenia skupiają się na programowej eliminacji drgań styków (debouncing), współbieżności bez blokowania procesora (wielozadaniowość z `millis()`) oraz obsłudze wyświetlacza LCD za pomocą magistrali I2C.

Kody w tym laboratorium zostały napisane z wykorzystaniem **Programowania Obiektowego (OOP)** w C++ (własne klasy: `Button`, `RgbLed`, `AsyncLed`, `Stopwatch`), co zapewnia modułowość i czytelność typową dla projektów w środowisku PlatformIO.

## Połączenia sprzętowe
Programy zostały napisane dla płytki Arduino UNO z wykorzystaniem następujących połączeń:
*   **Dioda RGB (wspólna katoda):**
    *   Anoda czerwona (Red) -> Pin `D6`
    *   Anoda zielona (Green) -> Pin `D5`
    *   Anoda niebieska (Blue) -> Pin `D3`
*   **Przyciski (monostabilne):**
    *   Czerwony przycisk -> Pin `D2` (Wymaga wbudowanego rezystora podciągającego `INPUT_PULLUP`)
    *   Zielony przycisk -> Pin `D4` (Wymaga wbudowanego rezystora podciągającego `INPUT_PULLUP`)
*   **Wyświetlacz LCD (16x2) z konwerterem I2C:**
    *   SDA -> `A4` (lub dedykowany pin SDA)
    *   SCL -> `A5` (lub dedykowany pin SCL)
    *   VCC -> `5V`
    *   GND -> `GND`
    *   *Adres magistrali I2C:* `0x27`

---

## Opis Programów

### Zadanie 1: Program z eliminacją wpływu drgania styków
Program demonstruje, jak poradzić sobie z problemem mechanicznego odbijania styków przycisku przy użyciu nieblokującej metody opartej na funkcji `millis()` (zamkniętej w klasie `Button`).
*   **Zarówno Czerwony, jak i Zielony przycisk:** Powodują przejście diody RGB do następnego koloru w cyklu (Czerwony -> Zielony -> Niebieski).
*   *Zastosowane mechanizmy:* Hermetyzacja klas, maszyny stanów, detekcja momentu zwolnienia przycisku (`wasReleased()`), omijanie problemów sprzętowych na drodze programowej.

### Zadanie 2: Program wykonujący współbieżnie różne zadania
Program udowadnia, że jednordzeniowy mikrokontroler potrafi obsługiwać wiele procesów równocześnie bez wzajemnego blokowania się, całkowicie eliminując użycie funkcji `delay()`.
*   **Diody LED:** Czerwona, zielona i niebieska dioda migają z zupełnie innymi interwałami (odpowiednio co 0.9s, 1.0s i 1.1s) zarządzanymi przez klasę `AsyncLed`.
*   **Przycisk:** Czerwony przycisk może zostać wciśnięty w dowolnym momencie, by wysłać komunikat przez port szeregowy (Serial Monitor), nie zaburzając przy tym rytmu migania diod.
*   *Zastosowane mechanizmy:* Śledzenie upływu czasu funkcją `millis()`, kod nieblokujący, wykonywanie asynchroniczne.

### Zadanie 3: Program "Stoper elektroniczny" (Wyświetlacz LCD)
Program realizuje w pełni funkcjonalny stoper z wykorzystaniem wyświetlacza sprzętowego. Aktualizacja danych na ekranie następuje w sposób selektywny (bez czyszczenia całego ekranu funkcją `clear()`), by uniknąć migotania.
*   **Zielony przycisk:** Przełącza stan stopera (Start / Pauza).
*   **Czerwony przycisk:** Zatrzymuje stoper i resetuje zliczony czas do zera.
*   **Wyświetlacz LCD:** Wyświetla nagłówek "Stoper", upływający czas w sekundach oraz wskaźnik obecnego stanu (`>` dla pracy, `||` dla pauzy).
*   *Zastosowane mechanizmy:* Komunikacja po magistrali I2C, biblioteka `LiquidCrystal_I2C`, częściowe nadpisywanie ekranu LCD, precyzyjne kumulowanie czasu w klasie `Stopwatch`.