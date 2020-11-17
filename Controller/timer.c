#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.h"

void timer_init(void)
{
	//timer0
	TCCR0A = 0x00; //Timer/Counter Control Register 0 A. Set to reset value.
	TCCR0A |= (1 << WGM01); //Timer/Counter Control Register 0 A. Set second bit (WGM01) to 1 for CTC mode. 

	TCCR0B = 0x00; //Timer/Counter Control Register 0 B. Set to reset value.
	TCCR0B |= (1 << CS00) | (1 << CS02); //Timer/Counter Control Register 0 B. Set first (CS00) and third (CS02) to 1 for prescaler=1024.

	TCNT0 = 0x00; //Timer/Counter Register (stores the counter value). Set to 0 to initiate.
	OCR0A = 0x9C; //Output Compare Register. Set to 156 for 10ms cycle.
	TIMSK0 |= (1 << OCIE0A);//Compare match interrupt

    sei();
}

