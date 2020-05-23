#include <Arduino.h>
#include <avr/interrupt.h>
#define ADC_RESOLUTION_DEFAULT (5.0f / 1024.0f)

uint16_t digital;
float voltage;

uint16_t ADCsingleREAD(uint8_t adcToUse)
{
  uint16_t ADCval;
  while (ADCSRA & (1 << ADSC))
    ;
  ADCval = ADCL;
  ADCval = (ADCH << 8) + ADCval;
  
  return ADCval;
}
void setup()
{
  ADMUX = 0;
  ADMUX |= (1 << REFS0);
  ADMUX &= ~(1 << ADLAR);
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  ADCSRA |= (1 << ADEN);
  ADCSRA |=B01000000;
  sei();
 
  // Kick off the first ADC
  Serial.begin(9600);
}

void loop()
{
  digital = ADCsingleREAD(0);
  voltage = ADC_RESOLUTION_DEFAULT * digital;
  Serial.print("A0 = ");
  Serial.print(digital);
  Serial.print("\t V(0) = ");
  Serial.print(voltage);
  Serial.print(" [V]\n");
  delay(1000);
}

ISR(ADC_vect)
{
    ADCSRA |= (1 << ADSC);
}