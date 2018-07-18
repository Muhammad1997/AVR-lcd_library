/*
 * my_lcd.h
 *
 * Created: 7/13/2018 3:54:32 PM
 *  Author: muhammad magdy
 */ 
#ifndef MY_LCD_H_
#define MY_LCD_H_

#define LCD_Data_Dir DDRB	    /* Define LCD data port direction */
#define LCD_Command_Dir DDRC	/* Define LCD command port direction register */
#define LCD_Data_Port PORTB	    /* Define LCD data port */
#define LCD_Command_Port PORTC	/* Define LCD data port */
#define RS PC0			        /* Define Register Select signal pin */
#define RW PC1			        /* Define Read/Write signal pin */
#define EN PC6			        /* Define Enable signal pin */

void Lcd_Cmd(char cmnd);
void Lcd_Command(char *Command);
void Lcd_Init (void);
void Lcd_Chr(unsigned char char_data);
void Lcd_Out_Cp(char *str);
void Lcd_Out(char row, char pos, char *str);
void Lcd_Clear();
void Lcd_Custom_Char (unsigned char loc, unsigned char *msg);
void Lcd_Custom_Out(char row, char pos,char loc);


#endif /* MY_LCD_H_ */