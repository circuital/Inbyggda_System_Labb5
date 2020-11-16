#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "serial.h"
#include "buttons.h"
#include "timer.h"

char command;

ISR(TIMER0_COMPA_vect)
{
    command = get_button_command();
    uart_send_command(command);
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