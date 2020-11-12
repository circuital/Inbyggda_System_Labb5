#include <avr/io.h>

#include <stdio.h>

#include "buttons.h"
#include "serial.h"

void buttons_init(void)
{
	DDRB &= ~(1 << PB0); //forwad
	DDRB &= ~(1 << PB1); // backward
	DDRB &= ~(1 << PB2); // left
	DDRB &= ~(1 << PB3); // right
}

//void button_click_forward()
//{
//	if (PINB & (1 << PB0))
//}
//
//void button_click_backward()
//{
//	if (PINB & (1 << PB1))
//}
//
//void button_click_left()
//{
//	if (PINB & (1 << PB2))
//}
//
//void button_click_right()
//{
//	if (PINB & (1 << PB3))
//}
