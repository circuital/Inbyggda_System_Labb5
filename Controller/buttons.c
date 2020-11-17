#include <avr/io.h>
#include <stdio.h>

#include "buttons.h"

void buttons_init(void)
{
	DDRB &= ~(1 << PB0); //FORWARD
	DDRB &= ~(1 << PB1); // BACK
	DDRB &= ~(1 << PB2); // LEFT
	DDRB &= ~(1 << PB3); // RIGHT
	DDRB &= ~(1 << PB4); // MODE CHANGER
	DDRB &= ~(1 << PB5); // START
}

char get_button_command()
{
    if ((PINB & (1 << PB0)) && !(PINB & (1 << PB1)) && !(PINB & (1 << PB2)) && !(PINB & (1 << PB3)))
    {
        return FORWARD; //FORWARD
    }
    else if ((PINB & (1 << PB1)) && !(PINB & (1 << PB0)) && !(PINB & (1 << PB2)) && !(PINB & (1 << PB3)))
    {
        return BACK; //BACK
    }
    else if ((PINB & (1 << PB2)) && !(PINB & (1 << PB0)) && !(PINB & (1 << PB1)) && !(PINB & (1 << PB3)))
    {
        return LEFT; //LEFT
    }
    else if ((PINB & (1 << PB3)) && !(PINB & (1 << PB0)) && !(PINB & (1 << PB1)) && !(PINB & (1 << PB2)))
    {
        return RIGHT; //RIGHT
    }
    else if ((PINB & (1 << PB0)) && (PINB & (1 << PB2)) && !(PINB & (1 << PB1)) && !(PINB & (1 << PB3)))
    {
        return FORWARDLEFT; //FORWARDLEFT
    }
    else if ((PINB & (1 << PB0)) && (PINB & (1 << PB3)) && !(PINB & (1 << PB1)) && !(PINB & (1 << PB2)))
    {
        return FORWARDRIGHT; //FORWARDRIGHT
    }
    else if ((PINB & (1 << PB1)) && (PINB & (1 << PB2)) && !(PINB & (1 << PB0)) && !(PINB & (1 << PB3)))
    {
        return BACKLEFT; //BACKLEFT
    }
    else if ((PINB & (1 << PB1)) && (PINB & (1 << PB3)) && !(PINB & (1 << PB0)) && !(PINB & (1 << PB2)))
    {
        return BACKRIGHT; //BACKRIGHT
    }
    else if (PINB & (1 << PB4))
    {
        return CHANGEMODE; //CHANGEMODE
    }
    else if (PINB & (1 << PB5))
    {
        return START; //START
    }
    else
    {
        return STOP; //STOP
    }
}
