// IDENTYFIKATORY

// PINY LED
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

// STALE
const byte LED_PINS[] = {LED_RED, LED_GREEN, LED_BLUE};
const byte LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

const byte BRIGHTNESS_STEP = 5;
const byte MAX_BRIGHTNESS = 255;

const int FADE_DELAY = 50;

// ZMIENNE STANU PROGRAMU
byte currentLedIndex = 0;
byte nextLedIndex = 1;

// FUNKCJE

// funkcja inicjalizujaca piny diod LED
void initRgb() {
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, LOW);

  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, LOW);

  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, LOW);
}

// FUNKCJE ARDUINO

void setup() {
  // inicjalizacja diod LED
  initRgb();
  analogWrite(LED_PINS[currentLedIndex], MAX_BRIGHTNESS);
}

void loop() {
  // jedna dioda gasnie nastepna rozjasnia sie
  int brightness = 0;
  const byte fadeStep = BRIGHTNESS_STEP == 0 ? 1 : BRIGHTNESS_STEP;

  while (true) {
    analogWrite(LED_PINS[currentLedIndex], MAX_BRIGHTNESS - brightness);
    analogWrite(LED_PINS[nextLedIndex], brightness);
    delay(FADE_DELAY);

    if (brightness == MAX_BRIGHTNESS) {
      break;
    }

    brightness += fadeStep;
    if (brightness > MAX_BRIGHTNESS) {
      brightness = MAX_BRIGHTNESS;
    }
  }

  currentLedIndex = nextLedIndex;
  nextLedIndex = (nextLedIndex + 1) % LED_COUNT;
}