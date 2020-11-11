#include <avr/io.h>        //standard AVR library
#include <util/delay.h>     // delay library
#include "dcmotor.h"


int main(void)
{
    dcmotor1_init();
    dcmotor2_init();

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

        dcmotor2_forward();
        _delay_ms(3000);    //delay of 3 sec
        dcmotor2_stop();
        _delay_ms(1000);    //delay of 1 sec
        dcmotor2_back();
        _delay_ms(3000);    //delay of 3 sec
        dcmotor2_stop();
        _delay_ms(1000);    //delay of 1 sec
    }
}