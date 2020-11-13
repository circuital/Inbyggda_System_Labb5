#include <avr/io.h>        //standard AVR library
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>     // delay library
  
#include <avr/interrupt.h>

#include "serial.h"
#include "dcmotor.h"

static volatile char controllerCommand;

ISR(USART_RX_vect)
{
controllerCommand = UDR0;
}

int main(void)
{
    dcmotor_init();
    uart_init();


    while (1)   //infinite loop
    {
        motor_executer(controllerCommand);
    }
}