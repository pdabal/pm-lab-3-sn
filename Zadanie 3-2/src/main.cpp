#include <Arduino.h>

#define BUTTON 2
uint16_t liczba_nacisniec = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON,INPUT);
}

void loop()
{
  if (digitalRead(BUTTON))
  {
    Serial.print("Liczba nacisniec przyciskow: ");
    Serial.println(++liczba_nacisniec);
  }
}