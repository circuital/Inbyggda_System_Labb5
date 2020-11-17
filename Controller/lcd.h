#ifndef LCD_H_
#define LCD_H_

void LCD_Init(void);

void LCD_Command(unsigned char cmnd);

void LCD_Char(unsigned char data);

void LCD_Clear();

void LCD_String(char *str);

void LCD_String_xy(char row, char pos, char *str);

void LCD_state_handler(char command);

void LCD_state_executer(char command);

void STEM_LCD_Print(char command);

#endif //LCD