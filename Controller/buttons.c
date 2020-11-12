#include <avr/io.h>
#include <stdio.h>

#include "buttons.h"

void buttons_init(void)
{
	DDRB &= ~(1 << PB0); //forwad
	DDRB &= ~(1 << PB1); // backward
	DDRB &= ~(1 << PB2); // left
	DDRB &= ~(1 << PB3); // right
}
