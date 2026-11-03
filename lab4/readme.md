# IoT Basics - Lab 4: Serial Communication & ADC

This repository contains solutions for Laboratory 4 of the "Internet of Things Basics" (Podstawy Internetu Rzeczy) course at Wrocław University of Science and Technology (PWr). The lab focuses on UART serial communication (sending and receiving data) and the Analog-to-Digital Converter (ADC) using a potentiometer.

The code in this laboratory utilizes an advanced **Object-Oriented Programming (OOP)** architecture. It introduces the **Command Design Pattern** for the serial Command Line Interface (CLI) to ensure the Open/Closed Principle, as well as a dedicated `Potentiometer` wrapper class for ADC measurements.

## Hardware Setup
The projects are designed for an Arduino UNO board with the following connections:
*   **RGB LED (Common Cathode):** Red -> Pin `D6`, Green -> Pin `D5`, Blue -> Pin `D3`
*   **Push Buttons (Normally Open):** Red Button -> Pin `D2`, Green Button -> Pin `D4` (Configured as `INPUT_PULLUP`)
*   **LCD Display (16x2) with I2C:** SDA -> `A4`, SCL -> `A5`
*   **Potentiometer (Rotary/Trimmer):**
    *   Pin 1 -> `5V`
    *   Pin 2 (Wiper/Middle) -> Analog Pin `A0`
    *   Pin 3 -> `GND`

---

## Programs Overview

### Task 1: Sending Data to Serial Plotter (Buttons)
This program reads the states of the physical buttons and transmits them over the UART interface at a high baud rate (115200). 
*   The data is formatted as comma-separated values (`Red: 1, Green: 0`), which allows the **Serial Plotter** tool in the Arduino IDE to generate real-time live graphs of the button interactions.
*   *Key concepts:* `Serial.begin()`, baud rates, `Serial.print()`, timing with `millis()`.

### Task 2: PC to Arduino Serial Control (Command Pattern CLI)
A robust Command Line Interface allowing the user to control the Arduino's RGB LED via the Serial Monitor.
*   **Architecture:** Uses the `SerialCli` class as an invoker and the `Command` interface to handle specific user inputs without cluttering the main loop. 
*   **Commands:** 
    *   `rgb <R> <G> <B>` (e.g., `rgb 255 0 128`) - sets the specific PWM values for the LED. Includes boundaries checking (0-255).
    *   `off` - turns the LED off entirely.
*   *Key concepts:* String parsing (`sscanf`), non-blocking serial reading (`readStringUntil`), Command Design Pattern, Dependency Injection.

### Task 3: Potentiometer Voltage to LCD
Reads analog voltage from the potentiometer and displays the results on the I2C LCD screen.
*   The raw ADC value (0-1023) is read using the `Potentiometer` class.
*   The physical voltage (0.00V - 5.00V) is dynamically calculated based on the $V_{IN} = \frac{V_{REF}}{2^{n}} * N_{ADC}$ formula.
*   *Key concepts:* Analog-to-Digital Converter (ADC), `analogRead()`, mathematical voltage scaling, partial LCD refreshing.

### Task 4: Potentiometer to Serial Plotter
Sends the analog readings to the PC to be visualized on a live graph.
*   Outputs both the raw ADC value (0-1023) and the scaled voltage (converted to millivolts/microvolts for a better scale match on the plotter grid).
*   *Key concepts:* Multi-variable serial plotting, ADC noise observation.

---
---

# Podstawy Internetu Rzeczy - Laboratorium 4: Komunikacja szeregowa i Przetwornik ADC

Repozytorium zawiera kody źródłowe stanowiące rozwiązania zadań z Laboratorium 4 w ramach przedmiotu "Podstawy Internetu Rzeczy" (Politechnika Wrocławska). Ćwiczenia skupiają się na dwukierunkowej komunikacji szeregowej (UART) pomiędzy komputerem a mikrokontrolerem oraz na obsłudze Przetwornika Analogowo-Cyfrowego (ADC) za pomocą potencjometru.

Kody w tym laboratorium wykorzystują zaawansowaną architekturę **Programowania Obiektowego (OOP)**. Wprowadzono **wzorzec projektowy Polecenie (Command Pattern)** do obsługi interfejsu tekstowego (CLI), co gwarantuje łatwą rozbudowę (Open/Closed Principle), a także dedykowaną klasę `Potentiometer` opakowującą logikę odczytów ADC.

## Połączenia sprzętowe
Programy zostały napisane dla płytki Arduino UNO z wykorzystaniem następujących połączeń:
*   **Dioda RGB (wspólna katoda):** Red -> Pin `D6`, Green -> Pin `D5`, Blue -> Pin `D3`
*   **Przyciski (monostabilne):** Czerwony -> Pin `D2`, Zielony -> Pin `D4` (`INPUT_PULLUP`)
*   **Wyświetlacz LCD (16x2) I2C:** SDA -> `A4`, SCL -> `A5`
*   **Potencjometr:**
    *   Nóżka 1 -> `5V`
    *   Nóżka 2 (Ślizgacz/Środek) -> Pin analogowy `A0`
    *   Nóżka 3 -> `GND`

---

## Opis Programów

### Zadanie 1: Wysyłanie danych do Serial Plotter (Przyciski)
Program odczytuje fizyczne stany przycisków i wysyła je przez interfejs UART z dużą prędkością (115200 baud).
*   Dane są formatowane z użyciem przecinków (`Red: 1, Green: 0`), co pozwala narzędziu **Serial Plotter** (w Arduino IDE) na rysowanie płynnych wykresów na żywo w momencie wciskania przycisków.
*   *Zastosowane mechanizmy:* `Serial.begin()`, prędkości transmisji (baud rate), funkcja `Serial.print()`, sterowanie czasem przez `millis()`.

### Zadanie 2: Sterowanie Arduino z poziomu PC (Wzorzec Command)
Rozbudowany interfejs wiersza poleceń (CLI) pozwalający użytkownikowi na sterowanie diodą RGB w Arduino za pomocą Serial Monitora.
*   **Architektura:** Wykorzystuje klasę `SerialCli` jako kontroler (invoker) oraz interfejs `Command` do obsługi poszczególnych poleceń, zachowując idealny porządek w pętli `loop()`.
*   **Komendy:** 
    *   `rgb <R> <G> <B>` (np. `rgb 255 0 128`) - ustawia konkretne wypełnienie PWM dla diody (z zabezpieczeniem zakresu 0-255).
    *   `off` - całkowicie gasi diodę.
*   *Zastosowane mechanizmy:* Parsowanie tekstu (`sscanf`), nieblokujące czytanie bufora (`readStringUntil`), Wzorzec Projektowy Polecenie (Command), wstrzykiwanie zależności.

### Zadanie 3: Napięcie z potencjometru na ekranie LCD
Program odczytuje napięcie analogowe z potencjometru i wyświetla wyniki na ekranie LCD I2C.
*   Surowa wartość z przetwornika (0-1023) odczytywana jest przez klasę `Potentiometer`.
*   Fizyczne napięcie (0.00V - 5.00V) jest dynamicznie obliczane na podstawie wzoru $V_{IN} = \frac{V_{REF}}{2^{n}} * N_{ADC}$.
*   *Zastosowane mechanizmy:* Przetwornik Analogowo-Cyfrowy (ADC), `analogRead()`, skalowanie matematyczne napięcia, odświeżanie częściowe ekranu LCD.

### Zadanie 4: Potencjometr i Serial Plotter
Wysyłanie odczytów analogowych do komputera PC w celu ich wizualizacji na żywo.
*   Program wysyła jednocześnie surową wartość ADC (0-1023) oraz wyliczone napięcie (przeskalowane na miliwolty w celu lepszego dopasowania obu wartości na jednej siatce wykresu).
*   *Zastosowane mechanizmy:* Rysowanie wielu zmiennych w Serial Plotterze, obserwacja szumów na przetworniku ADC.