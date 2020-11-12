#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "serial.h"

int main(void)
{
    uart_init();

    while (1)
    {
        if (!(PINB & (1 << PB0)))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'F'; //FORWARD
        }

        else if (!(PINB & (1 << PB1)))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'B'; //BACK
        }
        else if (!(PINB & (1 << PB2)))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'L'; //LEFT
        }
        else if (!(PINB & (1 << PB3)))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'R'; //RIGHT
        }
        else
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = 'S'; //STOP
        }
    }

    return 0;
}