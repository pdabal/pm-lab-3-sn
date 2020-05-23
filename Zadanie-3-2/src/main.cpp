#include <Arduino.h>

uint8_t i = 0;

void setup()
{
  Serial.begin(9600)
  Serial.println("Witaj programisto!");
}

viod loop()
{
  Serial.println(i);
  delay(2000);
}