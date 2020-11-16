#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.h"

void timer_init(void)
{
	//timer0
	TCCR0A = 0x00; //Timer/Counter Control Register 0 A. S�tter till dess reset - v�rde.
	TCCR0A |= (1 << WGM01); //Timer/Counter Control Register 0 A. S�tter andra biten (WGM01) till 1 f�r CTC mode. 

	TCCR0B = 0x00; //Timer/Counter Control Register 0 B. S�tter till dess reset - v�rde.
	TCCR0B |= (1 << CS00) | (1 << CS02); //Timer/Counter Control Register 0 B. S�tter f�rsta (CS00) och tredje (CS02) till 1 f�r prescaler=1024.

	TCNT0 = 0x00; //Timer/Counter Register (stores the counter value). S�tter till 0 f�r att initiera. 
	OCR0A = 0x9C; //Output Compare Register. S�tter till 156. 

    sei();
}

