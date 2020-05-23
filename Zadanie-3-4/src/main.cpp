#include <Arduino.h>
#define PIN_G 5
#define PIN_B 6
#define PIN_R 9

int r,g,b;

void setup () {
    pinMode(PING_G, OUTPUT);
    pinMode(PING_B, OUTPUT);
    pinMode(PING_R, OUTPUT);
}

void loop() {
  analogWrite(PIN_R, rand());
  analogWrite(PIN_G, rand());
  analogWrite(PIN_B, rand());
  delay(1000);
}