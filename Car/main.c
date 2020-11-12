#include <avr/io.h>        //standard AVR library
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>     // delay library

#include "serial.h"
#include "dcmotor.h"


int main(void)
{
    dcmotor_init();
    uart_init();


    //DDRB |= (1 << PB0);

    while (1)   //infinite loop
    {
   
        right();
        _delay_ms(1000);

        dcmotor1_stop();
        dcmotor2_stop();
        left();
        _delay_ms(1000);

        dcmotor1_stop();
        dcmotor2_stop();
        back();
        _delay_ms(1000);

        dcmotor1_stop();
        dcmotor2_stop();
        forward();
        _delay_ms(1000);

        dcmotor1_stop();
        dcmotor2_stop();
        _delay_ms(1000);

    //    char c = uart_getchar();
    //    if (c == '1')
    //    {
    //        forward();
    //    }
    //    else if (c == '2')
    //    {
    //        back();
    //    }
    //    else if (c == '3')
    //    {
    //        left();
    //    }
    //    else if (c == '4')
    //    {
    //        right();
    //    }
    //    else
    //    {
    //        dcmotor1_stop();
    //        dcmotor2_stop();
    //    }
    //    printf_P(PSTR("%c\n"), c);
    }
}