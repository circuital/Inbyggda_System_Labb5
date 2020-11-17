#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include <stdio.h>
#include <string.h>

#include "timer.h"
#include "dcmotor.h"

static char STEM_commands[10];	

void dcmotor_init(void)
{
	//Motor controlling forward and back
	DDRB |= (1 << PB0); //Set pin 8 on Arduino board to output
	DDRB |= (1 << PB1); //Set pin 9 on Arduino board to output

	//Motor controlling left and right
	DDRB |= (1 << PB2); //Set pin 10 on Arduino board to output
	DDRB |= (1 << PB3); //Set pin 11 on Arduino board to output
}

void forward(void)
{
	PORTB |= (1 << PB0); //Set pin 8 on Arduino board to HIGH
	PORTB &= ~(1 << PB1); //Set pin 9 on Arduino board to LOW
}

void back(void)
{
	PORTB &= ~(1 << PB0); //Set pin 8 on Arduino board to LOW
	PORTB |= (1 << PB1); //Set pin 9 on Arduino board to HIGH
}

void left(void)
{
	PORTB &= ~(1 << PB2); //Set pin 10 on Arduino board to LOW
	PORTB |= (1 << PB3); //Set pin 11 on Arduino board to HIGH
}

void right(void)
{
	PORTB |= (1 << PB2); //Set pin 10 on Arduino board to HIGH
	PORTB &= ~(1 << PB3); //Set pin 11 on Arduino board to LOW
}

void forwardleft(void)
{
	PORTB |= (1 << PB0); //Set pin 8 on Arduino board to HIGH
	PORTB &= ~(1 << PB1); //Set pin 9 on Arduino board to LOW

	PORTB &= ~(1 << PB2); //Set pin 10 on Arduino board to LOW
	PORTB |= (1 << PB3); //Set pin 11 on Arduino board to HIGH
}
void forwardright(void)
{
	PORTB |= (1 << PB0); //Set pin 8 on Arduino board to HIGH
	PORTB &= ~(1 << PB1); //Set pin 9 on Arduino board to LOW

	PORTB |= (1 << PB2); //Set pin 10 on Arduino board to HIGH
	PORTB &= ~(1 << PB3); //Set pin 11 on Arduino board to LOW
}

void backleft(void)
{
	PORTB &= ~(1 << PB0); //Set pin 8 on Arduino board to LOW
	PORTB |= (1 << PB1); //Set pin 9 on Arduino board to HIGH

	PORTB &= ~(1 << PB2); //Set pin 10 on Arduino board to LOW
	PORTB |= (1 << PB3); //Set pin 11 on Arduino board to HIGH
}

void backright(void)
{
	PORTB &= ~(1 << PB0); //Set pin 8 on Arduino board to LOW
	PORTB |= (1 << PB1); //Set pin 9 on Arduino board to HIGH

	PORTB |= (1 << PB2); //Set pin 10 on Arduino board to HIGH
	PORTB &= ~(1 << PB3); //Set pin 11 on Arduino board to LOW
}

void dcmotor1_stop(void)
{
	PORTB &= ~(1 << PB0); //Set pin 8 on Arduino board to LOW
	PORTB &= ~(1 << PB1); //Set pin 9 on Arduino board to LOW
}

void dcmotor2_stop(void)
{
	PORTB &= ~(1 << PB2); //Set pin 10 on Arduino board to LOW
	PORTB &= ~(1 << PB3); //Set pin 11 on Arduino board to LOW
}

void basic_executer(char command)
{
	switch (command)
	{
	case '1':
		forward();
		break;
	case '2':
		back();
		break;
	case '3':
		left();
		break;
	case '4':
		right();
		break;
	case '5':
		forwardleft();
		break;
	case '6':
		forwardright();
		break;
	case '7':
		backleft();
		break;		
	case '8':		
		backright();
		break;
	case '0':
		dcmotor1_stop();
		dcmotor2_stop();
		break;
	default:
		break;
	}
}

void STEM_save_to_array(char command)
{
	static int i = 0;
	static char lastCommand;
	if (command == 'S' || i == 10)
	{
		STEM_read_array();
		i = 0;
	}
	if (command != '0' && command != lastCommand)
	{
		STEM_commands[i] = command;
		i++;
	}
	lastCommand = command;
}

void STEM_read_array()
{
	int j;
	for(j = 0; j < sizeof(STEM_commands); j++)
	{
		STEM_executer(STEM_commands[j]);
	}
	dcmotor1_stop();
	dcmotor2_stop();
}

void STEM_executer(char command)
{
	static int car_dir = 0; //Car direction, 0 = forward, 1 = back, forward by default
	int stop = 0;

	switch (command)
	{
	case '1':
		car_dir = 0; //Set the direction to forward
		while (stop == 0)
		{
			forward();
			stop = timer_executer();
		}
		break;
	case '2':
		car_dir = 1; //Set the direction to back
		while (stop == 0)
		{
			back();
			stop = timer_executer();
		}
		break;
	case '3':
		if (car_dir == 0)
		{
			while (stop == 0)
			{
				forwardleft();
				stop = timer_executer();
			}
		}
		else if (car_dir == 1)
		{
			while (stop == 0)
			{
				backleft();
				stop = timer_executer();
			}
		}
		break;
	case '4':
		if (car_dir == 0)
		{
			while (stop == 0)
			{
				forwardright();
				stop = timer_executer();
			}
		}
		else if (car_dir == 1)
		{
			while (stop == 0)
			{
				backright();
				stop = timer_executer();
			}
		}
		break;
	default:
		break;
	}
}