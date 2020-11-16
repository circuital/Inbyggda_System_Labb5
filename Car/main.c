#include <avr/io.h>        //standard AVR library
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>     // delay library
  
#include <avr/interrupt.h>

#include "serial.h"
#include "dcmotor.h"
static uint8_t state = 0;
static volatile char controllerCommand;

ISR(USART_RX_vect) //Triggered at UART receive
{
    controllerCommand = UDR0;
}

void state_handler(char command)
{
    if (command == 'C')
    {
        if (state == 0)
        {
            state = 1;
        }
        else if (state == 1)
        {
            state = 0;
        }
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


    while (1)   //infinite loop
    {
        //motor_executer(controllerCommand);
        state_handler(controllerCommand);
        state_executer(controllerCommand);
        printf_P(PSTR(" %c\n"), controllerCommand);
    }
}
