#include <avr/io.h>        //standard AVR library
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>     // delay library
  
#include <avr/interrupt.h>

#include "serial.h"
#include "dcmotor.h"
#include "timer.h"
static uint8_t state = 0;
static volatile char controllerCommand;

ISR(USART_RX_vect) //Triggered at UART receive
{
    controllerCommand = UDR0;
}

void state_handler()
{
    printf_P(PSTR(" state_handler\n"));
    if (state == 0)
    {
        state = 1;
        printf_P(PSTR(" %c\n"), state);
    }
    else if (state == 1)
    {
        state = 0;
        printf_P(PSTR(" %c\n"), state);
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
    dcmotor_init();
    uart_init();
    timer_init();


    while (1) 
    {
        //motor_executer(controllerCommand);
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
