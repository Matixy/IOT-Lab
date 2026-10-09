// IDENTYFIKATORY

// PINY LED
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

// PINY PRZYCISKOW
#define RED_BUTTON 2
#define GREEN_BUTTON 4

// ZMIENNE GLOBALNE
const int CHOSEN_LED = LED_GREEN;
const byte BRIGHTNESS_STEP = 5;
const byte MIN_BRIGHTNESS = 0;
const byte MAX_BRIGHTNESS = 255;
const int DELAY_TIME = 100;

// ZMIENNE STANU PROGRAMU
int ledBrightness = MAX_BRIGHTNESS;

// FUNKCJE

// funkcja inicjalizujaca piny diod LED
void initRgb() {
  pinMode(CHOSEN_LED, OUTPUT);
  digitalWrite(CHOSEN_LED, LOW);
}

// funkcja inicjalizujaca piny przyciskow
void initButtons() {
  pinMode(RED_BUTTON, INPUT_PULLUP); // INPUT_PULLUP - LOW wcisnety przycisk
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

// FUNKCJE ARDUINO

void setup() {
  // inicjalizacja diod LED i przyciskow
  initRgb();
  initButtons();

  // zapalenie diody zielonej
  analogWrite(CHOSEN_LED, ledBrightness);
}

void loop() {
  const bool redButtonState = digitalRead(RED_BUTTON);
  const bool greenButtonState = digitalRead(GREEN_BUTTON);

  // czerwony przycisk sciemnia
  if (redButtonState == LOW) {
    ledBrightness -= BRIGHTNESS_STEP;

    if (ledBrightness < MIN_BRIGHTNESS) {
      ledBrightness = MIN_BRIGHTNESS;
    }

    analogWrite(CHOSEN_LED, ledBrightness);
  }

  // zielony przycisk rozjasnia
  if (greenButtonState == LOW) {
    ledBrightness += BRIGHTNESS_STEP;

    if (ledBrightness > MAX_BRIGHTNESS) {
      ledBrightness = MAX_BRIGHTNESS;
    }

    analogWrite(CHOSEN_LED, ledBrightness);
  }

  // dodanie opoznienia aby pokazac efekt diody 
  delay(DELAY_TIME);
}