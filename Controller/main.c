#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "serial.h"
#include "buttons.h"

int main(void)
{
    uart_init();
    buttons_init();

    while (1)
    {
        if (PINB & (1 << PB0))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = FORWARD; //FORWARD
        }
        else if (PINB & (1 << PB1))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = BACK; //BACK
        }
        else if (PINB & (1 << PB2))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = LEFT; //LEFT
        }
        else if (PINB & (1 << PB3))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = RIGHT; //RIGHT
        }
        else if ((PINB & (1 << PB0)) && (PINB & (1 << PB2)))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = FORWARDLEFT; //FORWARDLEFT
        }
        else if ((PINB & (1 << PB0)) && (PINB & (1 << PB3)))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = FORWARDRIGHT; //FORWARDRIGHT
        }
        else if ((PINB & (1 << PB1)) && (PINB & (1 << PB2)))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = BACKLEFT; //BACKLEFT
        }
        else if ((PINB & (1 << PB1)) && (PINB & (1 << PB3)))
        {
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0 = BACKRIGHT; //BACKRIGHT
        }
    }
    return 0;
}