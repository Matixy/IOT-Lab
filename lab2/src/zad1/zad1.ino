//BIBLIOTEKI
#include <Wire.h>
#include <OneWire.h>

// IDENTYFIKATORY

// PINY LED
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

// PINY PRZYCISKOW
#define RED_BUTTON 2
#define GREEN_BUTTON 4

// ZMIENNE GLOBALNE

// Tablica pinow diod LED i liczba diod
const byte ledPins[] = {LED_RED, LED_GREEN, LED_BLUE}; // kolejnosc tablicy = kolejnosc zmian diod LED
const byte ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

// Zmienne stanu programu
byte currentLed = 0;
bool ledsEnabled = true;

bool previousRedButtonState = HIGH;
bool previousGreenButtonState = HIGH;

// FUNKCJE

// funkcja inicjalizujaca piny diod LED
void initRgb() {
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, LOW);

  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, LOW);

  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, LOW);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

// funkcja inicjalizujaca piny przyciskow
void initButtons() {
  pinMode(RED_BUTTON, INPUT_PULLUP); // INPUT_PULLUP - LOW to stan wcisnietego przycisku
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

// funkcja przelaczajaca stan diod LED
void toggleExternalLeds() {
  ledsEnabled = !ledsEnabled;
  
  const byte ledState = ledsEnabled ? HIGH : LOW;

  digitalWrite(ledPins[currentLed], ledState);
}

// funkcja przelaczajaca stan wbudowanej diody LED
void toggleBuiltinLed() {
  const byte ledState = digitalRead(LED_BUILTIN);
  digitalWrite(LED_BUILTIN, !ledState);
}

// funkcja zmieniajaca aktualnie wlaczona diode LED
void changeCurrentLed() {
  digitalWrite(ledPins[currentLed], LOW); // wylaczenie aktualnej diody
  currentLed = (currentLed + 1) % ledCount; // zmiana aktualnej diody na nastepna

  if (ledsEnabled) {
    digitalWrite(ledPins[currentLed], HIGH); // wlaczenie nowej diody
  }
}

// FUNKCJE ARDUINO

void setup() {
  // inicjalizacja diod LED i przyciskow
  initRgb();
  initButtons();

  // wyswietlenie poczatkowego stanu diod LED
  digitalWrite(ledPins[currentLed], HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  const bool redButtonState = digitalRead(RED_BUTTON);
  const bool greenButtonState = digitalRead(GREEN_BUTTON);

  // sprawdzenie czy czerwony przycisk zostal wcisniety
  if (previousRedButtonState == HIGH && redButtonState == LOW) {
    toggleExternalLeds();
    toggleBuiltinLed();
    delay(200); // debouncing - opoznienie zapobiega drganiom stykow przycisku
  }

  // sprawdzenie czy zielony przycisk zostal wcisniety
  if (previousGreenButtonState == HIGH && greenButtonState == LOW) {
    changeCurrentLed();
    delay(200); // debouncing - opoznienie zapobiega drganiom stykow przycisku
  }

  // aktualizacja stanu przyciskow
  previousRedButtonState = redButtonState;
  previousGreenButtonState = greenButtonState;
}