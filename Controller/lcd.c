#define F_CPU 16000000UL
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */

#define LCD_Dir  DDRD			/* Define LCD data port direction */
#define LCD_Port PORTD			/* Define LCD data port */
#define RS PD2				/* Define Register Select pin */
#define EN PD3				/* Define Enable signal pin */

char lastCommandLCD = '0';
uint8_t LCD_state = 0;
 

void LCD_Init (void)  /* LCD Initialize function */
{
	LCD_Dir = 0xFF;		/* Make LCD port direction as o/p */
	_delay_ms(20);		/* LCD Power ON delay always >15ms */
	
	LCD_Command(0x33);
	LCD_Command(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_Command(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c);	/* Display on cursor off */
	LCD_Command(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_Command(0x01);	/* Clear display screen */
    _delay_ms(2);
	LCD_Command (0x80);					/* Cursor 1st row 0th position */
}
 

void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);/* Sending upper nibble */
	LCD_Port &= ~ (1<<RS);		/* RS=0, command reg. */
	LCD_Port |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);/* Sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);/* Sending upper nibble */
	LCD_Port |= (1<<RS);  /* RS=1, data reg. */
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4);  /* Sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command (0x01);		/* Clear display */
	_delay_ms(2);
	LCD_Command (0x80);		/* Cursor at home position */
}

void LCD_state_handler(char command)
{
	if(command == 'C')
	{
		if (LCD_state == 0)
		{	
			LCD_state = 1;
			LCD_Clear();

		}
		else if (LCD_state == 1)
		{
			LCD_state = 0;
			LCD_Clear();
		}
	}
}

void LCD_state_executer(char command)
{
	if(LCD_state == 0)
	{
		LCD_Char('5');
	}
	else if (LCD_state == 1)
	{
		STEM_LCD_Print(command);
	}
}

void STEM_LCD_Print(char command)
{
	
	if (command != lastCommandLCD)
	{
		switch(command)
		{
			case '1':
				LCD_Char('F');
			break;
			case '2':
				LCD_Char('B');
			break;
			case '3':
				LCD_Char('R');
			break;
			case '4':
				LCD_Char('L');
			break;
			default:
			break;

		}

	}
	lastCommandLCD = command;
}