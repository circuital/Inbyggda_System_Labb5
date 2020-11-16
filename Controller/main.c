#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "serial.h"
#include "buttons.h"
#include "timer.h"

char command;
char commandArray[10];

ISR(TIMER0_COMPA_vect)
{
    //State 1
    command = get_button_command();
    uart_send_command(command);

    //State 2
    //commandArray = get_button_command_array();
    //uart_send_command_array(commandArray);
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