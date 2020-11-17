#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>    

#include "serial.h"
#include "timer.h"
#include "dcmotor.h"

static uint8_t state = 0;
static volatile char controllerCommand;

ISR(USART_RX_vect) //Triggered at UART receive
{
    controllerCommand = UDR0;
}

void state_handler()
{
    //Switch state
    if (state == 0)
    {
        state = 1;
    }
    else if (state == 1)
    {
        state = 0;
    }
}

void state_executer(char command)
{
    if (state == 0)
    {
        basic_executer(command);
    }
    else if (state == 1)
    {
        STEM_save_to_array(command);
    }
}
int main(void)
{
    uart_init();
    timer_init();
    dcmotor_init();

    while (1) 
    {
        if (controllerCommand == 'C')
        {
            state_handler();
            controllerCommand = '0';
        }
        else
        {
            state_executer(controllerCommand);
        }
    }
}
