#include <avr/io.h>        //standard AVR library
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>     // delay library

#include "serial.h"
#include "dcmotor.h"


int main(void)
{
    dcmotor1_init();
    dcmotor2_init();
    uart_init();

    DDRB |= (1 << PB0);

    while (1)   //infinite loop
    {
        //dcmotor1_forward();
        //_delay_ms(3000);    //delay of 3 sec
        //dcmotor1_stop();
        //_delay_ms(1000);    //delay of 1 sec
        //dcmotor1_back();
        //_delay_ms(3000);    //delay of 3 sec
        //dcmotor1_stop();
        //_delay_ms(1000);    //delay of 1 sec

        //dcmotor2_forward();
        //_delay_ms(3000);    //delay of 3 sec
        //dcmotor2_stop();
        //_delay_ms(1000);    //delay of 1 sec
        //dcmotor2_back();
        //_delay_ms(3000);    //delay of 3 sec
        //dcmotor2_stop();
        //_delay_ms(1000);    //delay of 1 sec

        char c = uart_getchar();
        //if (c == 'F')
        //{
        //    dcmotor1_forward();
        //}
        //else if (c == 'B')
        //{
        //    dcmotor1_back();
        //}
        //else if (c == 'L')
        //{
        //    dcmotor2_back();
        //}
        //else if (c == 'R')
        //{
        //    dcmotor2_forward();
        //}
        //else if (c == 'S')
        //{
        //    dcmotor1_stop();
        //    dcmotor2_stop();
        //}
        printf_P(PSTR("%c\n"), c);
    }
}