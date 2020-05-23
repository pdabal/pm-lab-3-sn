/*#include <Arduino.h>

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
}*/

/*#include <Arduino.h> 

#define BUTTON 2  

  

int stanPrzycisku; 

int poprzedniStanPrzycisku = LOW; 

unsigned long poprzedniCzas = 0; 

unsigned int liczba_nacisniec = 0; 

  

void setup() { 

  Serial.begin(9600); 

  pinMode(BUTTON, INPUT); 

} 

  

void loop() { 

  int odczyt = digitalRead(BUTTON); 

  

  if(odczyt != poprzedniStanPrzycisku) { 

    poprzedniCzas = millis(); 

  } 

  if ((millis() - poprzedniCzas) > 50) { 

    if (odczyt != stanPrzycisku == HIGH) { 

      liczba_nacisniec++; 

  

      Serial.print("Liczba nacisniec przycisku: "); 

      Serial.println(liczba_nacisniec); 

    } 

  } 

  { 

    poprzedniStanPrzycisku = odczyt; 

  } 

   

} */

#include <Arduino.h> 

#include <stdio.h> 

  

char rxBuff[32]; 

int bytesNo = 0; 

char paramStr[16]; 

int paramVal = 0; 

  

void setup() { 

    Serial.begin(9600); 

    Serial.setTimeout(4000); 

  

    pinMode(LED_BUILTIN, OUTPUT); 

} 

  

void loop() { 

    bytesNo = Serial.readBytesUntil('\r', rxBuff, sizeof(rxBuff) - 1); 

  

    sscanf(rxBuff, "%s %d", paramStr, &paramVal); 

  

    if (bytesNo) { 

        Serial.print("Wykonuje..."); 

        if (!strcmp(paramStr, "led")) { 

            if (paramVal) { 

                digitalWrite(LED_BUILTIN, HIGH); 

             } else { 

                 digitalWrite(LED_BUILTIN, LOW); 

             } 

                Serial.println("OK!");     

            } else if (!strcmp(paramStr, "blink")) { 

                for(int i = 0; i < paramVal; i++) { 

                    digitalWrite(LED_BUILTIN, HIGH); delay(500); 

                    digitalWrite(LED_BUILTIN, LOW); delay(500); 

                }  

                Serial.println("OK!"); 

            } else { 

                Serial.println("BLAD!"); 

            } 

        } 

    for (int i = 0; i < Serial.available(); i++) { 

        Serial.read(); 

    } 

    for (int i = 0; i < sizeof(rxBuff); i++) { 

        rxBuff[i] = 0; 

    } 

} 