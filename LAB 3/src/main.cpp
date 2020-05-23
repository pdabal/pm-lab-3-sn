#include <Arduino.h> 

#include <stdint.h> 

#define FOSC 16000000 

#define BAUD 9600 

#define MY_UBRR (FOSC / 16 / BAUD - 1) 

#define USE_UART_RX_IRQ 1
char receivedChar;
char Message[] = "Hello";
char *pMessage = Message;
void setup(){
UBRR0H = (MY_UBRR >> 8);
UBRR0L = MY_UBRR;
UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);

while (*pMessage){
  while ( !( UCSR0A & (1<<UDR0)));
  UDR0 = *pMessage;
  pMessage++;
}

#if (use_UART_RX_IRQ == 1)
UCSR0B |= (1 << RXCIE0);
#endif
}
void loop(){
  #if (USE_UART_RX_IRQ == 0)
  while (!(UCSR0A & (1 << RXC0)))
  ;
  receivedChar = UDR0;
  while (!(UCSR0A & (1 << UDRE0)))
  ;
  UDR0 = receivedChar;
  #endif 
}
#if (USE_UART_RX_IRQ == 1)
ISR (USART_RX_vect){
  receivedChar = UDR0;
  UDR0 = receivedChar;
}
#endif