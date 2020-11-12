#include <avr/io.h>

#include "timer.h"

void timer_init(void)
{
    //timer 0
    TCCR0A |= (1 << WGM01);//CTC mode.
    TCCR0B |= ((1 << CS02) | (1 << CS00));//1024
    OCR0A = 0x9C;//156, 10ms interrupt
    TIMSK0 |= (1 << OCIE0A);//comp_A interrupt
}

