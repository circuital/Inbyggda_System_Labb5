#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.h"

void timer_init(void)
{
	//timer0
	TCCR0A = 0x00; //Timer/Counter Control Register 0 A. Sätter till dess reset - värde.
	TCCR0A |= (1 << WGM01); //Timer/Counter Control Register 0 A. Sätter andra biten (WGM01) till 1 för CTC mode. 

	TCCR0B = 0x00; //Timer/Counter Control Register 0 B. Sätter till dess reset - värde.
	TCCR0B |= (1 << CS00) | (1 << CS02); //Timer/Counter Control Register 0 B. Sätter första (CS00) och tredje (CS02) till 1 för prescaler=1024.

	TCNT0 = 0x00; //Timer/Counter Register (stores the counter value). Sätter till 0 för att initiera. 
	OCR0A = 0x9C; //Output Compare Register. Sätter till 156. 

    sei();
}

