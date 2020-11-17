#ifndef LCD_H_
#define LCD_H_

void LCD_init(void);

void LCD_command(unsigned char cmnd);

void LCD_char(unsigned char data);

void LCD_clear();

void LCD_string(char *str);

void LCD_string_xy(char row, char pos, char *str);

void LCD_state_handler(char command);

void LCD_state_executer(char command);

void STEM_LCD_Print(char command);

#endif //LCD