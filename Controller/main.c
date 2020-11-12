#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "serial.h"

int main(void)
{
    uart_init();

    while (1)
    {
        if (PINB & (1 << PB0))
        {
            //printf_P(PSTR("%c\n"), 'F');
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'F'; //FORWARD
        }
        else if (PINB & (1 << PB1))
        {
            //printf_P(PSTR("%c\n"), 'B');
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'B'; //BACK
        }
        else if (PINB & (1 << PB2))
        {
            //printf_P(PSTR("%c\n"), 'L');
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'L'; //LEFT
        }
        else if (PINB & (1 << PB3))
        {
            //printf_P(PSTR("%c\n"), 'R');
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'R'; //RIGHT
        }
        else
        {
            //printf_P(PSTR("%c\n"), 'S');
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'S'; //STOP
        }
    }
    return 0;
}