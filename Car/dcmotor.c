#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include <stdio.h>
#include <string.h>

#include "dcmotor.h"

void dcmotor_init(void)
{

	/*motor for forward and back*/
	DDRB |= (1 << PB0); // set pin 8 on Arduino board to output
	DDRB |= (1 << PB1); // set pin 9 on Arduino board to output

	/*motor for left and right*/
	DDRB |= (1 << PB2); // set pin 10 on Arduino board to output
	DDRB |= (1 << PB3); // set pin 11 on Arduino board to output

}



void forward(void)
{
	PORTB |= (1 << PB0);// set pin 8 on Arduino board to HIGH
	PORTB &= ~(1 << PB1);// set pin 9 on Arduino board to LOW

}

void back(void)
{

	PORTB &= ~(1 << PB0);// set pin 8 on Arduino board to LOW
	PORTB |= (1 << PB1);// set pin 9 on Arduino board to HIGH
}

void right(void)
{
	PORTB |= (1 << PB2);// set pin 10 on Arduino board to HIGH
	PORTB &= ~(1 << PB3);// set pin 11 on Arduino board to LOW
}

void left(void)
{

	PORTB &= ~(1 << PB2);// set pin 10 on Arduino board to LOW
	PORTB |= (1 << PB3);// set pin 11 on Arduino board to HIGH
}

void forwardleft(void)
{
	PORTB |= (1 << PB0);// set pin 8 on Arduino board to HIGH
	PORTB &= ~(1 << PB1);// set pin 9 on Arduino board to LOW

	PORTB &= ~(1 << PB2);// set pin 10 on Arduino board to LOW
	PORTB |= (1 << PB3);// set pin 11 on Arduino board to HIGH
}
void forwardright(void)
{
	PORTB |= (1 << PB0);// set pin 8 on Arduino board to HIGH
	PORTB &= ~(1 << PB1);// set pin 9 on Arduino board to LOW

	PORTB |= (1 << PB2);// set pin 10 on Arduino board to HIGH
	PORTB &= ~(1 << PB3);// set pin 11 on Arduino board to LOW

}
void backleft(void)
{
	PORTB &= ~(1 << PB0);// set pin 8 on Arduino board to LOW
	PORTB |= (1 << PB1);// set pin 9 on Arduino board to HIGH

	PORTB &= ~(1 << PB2);// set pin 10 on Arduino board to LOW
	PORTB |= (1 << PB3);// set pin 11 on Arduino board to HIGH
}
void backright(void)
{
	PORTB &= ~(1 << PB0);// set pin 8 on Arduino board to LOW
	PORTB |= (1 << PB1);// set pin 9 on Arduino board to HIGH

	PORTB |= (1 << PB2);// set pin 10 on Arduino board to HIGH
	PORTB &= ~(1 << PB3);// set pin 11 on Arduino board to LOW
}

void dcmotor1_stop(void)
{
	PORTB &= ~(1 << PB0);// set pin 8 on Arduino board to LOW
	PORTB &= ~(1 << PB1);// set pin 9 on Arduino board to LOW
}

void dcmotor2_stop(void)
{
	PORTB &= ~(1 << PB2);// set pin 10 on Arduino board to LOW
	PORTB &= ~(1 << PB3);// set pin 11 on Arduino board to LOW
}