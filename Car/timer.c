#include <avr/io.h>
#include "timer.h"


void timer_init()
{
	/* CTC mode*/
	TCCR0A = 0; // set all pin i register to 0
	TCCR0A|= (1 << WGM01);   // CTC mode in register timer0
	TCCR0B |= (1 << CS02) | (1 << CS00);  // Set CS02 and CS01 bits for 1024 prescaler
	OCR0A = 155; //16000000/ (1024)*(0,01)-1
}

int timer_executer()
{
	static timer = 0;
	if (TIFR0 & (1 << OCF0A)) // check CTC flag
	{
		timer++;
	}
	TIFR0 = (1 << OCF0A); // reset flag
	if (timer == 100)
	{
		timer = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}