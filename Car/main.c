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


    //DDRB |= (1 << PB0);

    while (1)   //infinite loop
    {
       if (controllerCommand == '1')
       {
           forward();
       }
       else if (controllerCommand == '2')
       {
           back();
       }
       else if (controllerCommand == '3')
       {
           left();
       }
       else if (controllerCommand == '4')
       {
           right();
       }
       else if (controllerCommand == '5')
       {
           forwardleft();
       }
       else if (controllerCommand == '6')
       {
           forwardright();
       }
       else if (controllerCommand == '7')
       {
           backleft();
       }
       else if (controllerCommand == '8')
       {
           backright();
       }
       else
       {
           dcmotor1_stop();
           dcmotor2_stop();
       }
    }
}