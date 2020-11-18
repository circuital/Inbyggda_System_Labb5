#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_Dir  DDRD //Define LCD data port direction
#define LCD_Port PORTD //Define LCD data port
#define RS PD2 //Define Register Select pin
#define EN PD3 //Define Enable signal pin

char lastCommandLCD = '0';
char lastStateLCD = '0';
uint8_t LCD_state = 0;
int commandCounter = 0;

void LCD_init(void)
{
	LCD_Dir = 0xFF; //Make LCD port direction as o/p
	_delay_ms(20); //LCD Power ON delay always >15ms
	LCD_command(0x33);
	LCD_command(0x32); //Send for 4 bit initialization of LCD
	LCD_command(0x28); //2 line, 5*7 matrix in 4-bit mode
	LCD_command(0x0c); // Display on cursor off
	LCD_command(0x06); // Increment cursor (shift cursor to right)
	LCD_command(0x01); //Clear display screen
    _delay_ms(2);
	LCD_command (0x80); //Cursor 1st row 0th position

}
 
void LCD_command(unsigned char cmnd)
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); //Sending upper nibble
	LCD_Port &= ~ (1<<RS); // RS=0, command reg.
	LCD_Port |= (1 << EN); //Enable pulse
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4); //Sending lower nibble
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_char(unsigned char data)
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0); //Sending upper nibble
	LCD_Port |= (1<<RS); //RS=1, data reg
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4); //Sending lower nibble
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_string(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++) //Send each char of string till the NULL
	{
		LCD_char (str[i]);
	}
}

void LCD_string_xy (char row, char pos, char *str)
{
	if (row == 0 && pos < 16)
	{
		LCD_command((pos & 0x0F) | 0x80); //Command of first row and required position<16
	}
	else if (row == 1 && pos < 16)
	{
		LCD_command((pos & 0x0F) | 0xC0); //Command of first row and required position<16
	}
	LCD_string(str); //Call LCD string function
}

void LCD_clear()
{
	LCD_command (0x01); //Clear display
	_delay_ms(2);
	LCD_command (0x80);	//Cursor at home position
}

void LCD_state_handler(char command)
{
	if(command == 'C' && lastStateLCD != command) //needs a look over
	{
		if (LCD_state == 0)
		{	
			LCD_state = 1;
			LCD_clear();

		}
		else if (LCD_state == 1)
		{
			LCD_state = 0;
			LCD_clear();
		}
	}
	lastStateLCD = command;
}

void LCD_state_executer(char command)
{
	if(LCD_state == 0)
	{
		LCD_string_xy(0,0,"THIS IS A CAR");
		LCD_string_xy(1,0,"MOTHERFUCKERS");
	}
	else if (LCD_state == 1)
	{
		if (commandCounter >= 10 || command == 'S')
		{
			LCD_clear();
			commandCounter = 0;
		}
		else
		{
			STEM_LCD_Print(command);
			commandCounter++;
		}
		//STEM_LCD_Print(command);
	}
}

void STEM_LCD_Print(char command)
{
	
	if (command != lastCommandLCD)
	{
		switch(command)
		{
			case '1':
				LCD_char('F');
			break;
			case '2':
				LCD_char('B');
			break;
			case '3':
				LCD_char('R');
			break;
			case '4':
				LCD_char('L');
			break;
			default:
			break;

		}

	}
	lastCommandLCD = command;
}