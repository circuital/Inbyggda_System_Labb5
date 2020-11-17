#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "serial.h"
#include "buttons.h"
#include "timer.h"
#include "lcd.h"

volatile char command;

ISR(TIMER0_COMPA_vect) //Triggered at compare match
{
    command = get_button_command();
    uart_send_command(command);
}

int main(void)
{
    uart_init();
    timer_init();
    buttons_init();
    LCD_init();

    while (1)
    {
        LCD_state_handler(command);
        LCD_state_executer(command);
    }

    return 0;
}