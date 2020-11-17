#ifndef SERIAL_H_
#define SERIAL_H_

#define F_OSC 16000000 //Clock frequency
#define BAUD 38400 //Baud rate
#define UBRR (F_OSC/(16*BAUD))-1 //Baud rate register

void uart_init(void);

int uart_putchar(char chr, FILE* stream);

char uart_getchar(void);

#endif