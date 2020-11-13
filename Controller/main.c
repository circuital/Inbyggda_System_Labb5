#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "serial.h"
#include "buttons.h"
#include "timer.h"

ISR(TIMER0_COMPA_vect)
{
    uart_send_command(get_button_command());
}

int main(void)
{
    uart_init();
    timer_init();
    buttons_init();

    while (1)
    {
    }

    return 0;
}