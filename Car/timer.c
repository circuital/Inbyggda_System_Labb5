#include <avr/io.h>

#include "timer.h"

void timer_init()
{
	//timer0
	TCCR0A = 0x00; //Timer/Counter Control Register 0 A. Set to reset value.
	TCCR0A |= (1 << WGM01); //Timer/Counter Control Register 0 A. Set second bit (WGM01) to 1 for CTC mode. 
	
	TCCR0B = 0x00; //Timer/Counter Control Register 0 B. Set to reset value.
	TCCR0B |= (1 << CS00) | (1 << CS02); //Timer/Counter Control Register 0 B. Set first (CS00) and third (CS02) to 1 for prescaler=1024.
	
	TCNT0 = 0x00; //Timer/Counter Register (stores the counter value). Set to 0 to initiate.
	OCR0A = 0x9C; //Output Compare Register. Set to 156.
}

int timer_executer()
{
	static counter = 0;
	if (TIFR0 & (1 << OCF0A)) //Check CTC flag
	{
		counter++;
	}
	TIFR0 = (1 << OCF0A); //Reset CTC flag

	if (counter == 100)
	{
		counter = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}