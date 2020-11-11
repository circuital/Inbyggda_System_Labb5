
void dcmotor1_init(void)
{
	DDRB |= (1 << PB1); // set pin 9 on Arduino board to output
	DDRB |= (1 << PB0); // set pin 8 on Arduino board to output
}

void dcmotor2_init(void)
{
	DDRB |= (1 << PB3); // set pin 11 on Arduino board to output
	DDRB |= (1 << PB2); // set pin 10 on Arduino board to output
}

void dcmotor1_forward(void)
{
	PORTB |= (1 << PB0);// set pin 8 on Arduino board to HIGH
	PORTB &= ~(1 << PB1);// set pin 9 on Arduino board to LOW

}

void dcmotor2_forward(void)
{
	PORTB |= (1 << PB2);// set pin 0 on Arduino board to HIGH
	PORTB &= ~(1 << PB3);// set pin 9 on Arduino board to LOW
}

void dcmotor1_back(void)
{

	PORTB |= (1 << PB1);// set pin 0 on Arduino board to HIGH
	PORTB &= ~(1 << PB0);// set pin 9 on Arduino board to LOW
}

void dcmotor2_back(void)
{

	PORTB |= (1 << PB3);// set pin 0 on Arduino board to HIGH
	PORTB &= ~(1 << PB2);// set pin 9 on Arduino board to LOW
}

void dcmotor1_stop(void)
{
	PORTB &= ~(1 << PB0);// set pin 9 on Arduino board to LOW
	PORTB &= ~(1 << PB1);// set pin 9 on Arduino board to LOW
}

void dcmotor2_stop(void)
{
	PORTB &= ~(1 << PB2);// set pin 9 on Arduino board to LOW
	PORTB &= ~(1 << PB3);// set pin 9 on Arduino board to LOW
}