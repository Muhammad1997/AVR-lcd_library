/*
 * my_lcd.c
 *
 * Created: 7/13/2018 4:24:57 PM
 *  Author: muhammad magdy
 */ 
#include <avr/io.h>
#include <avr/delay.h>
#include <string.h>
#include "my_lcd.h"

void Lcd_Cmd(char cmnd)
{		
	LCD_Data_Port= cmnd;
	LCD_Command_Port &= ~(1<<RS);	/* RS=0 command reg. */
	LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
	LCD_Command_Port |= (1<<EN);	/* Enable pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(2);
}

void Lcd_Command(char *Command)
{
	
	char cmnd;
	if      (strcmp(Command,"_LCD_CLEAR") == 0) {cmnd = 0x01;}
	else if (strcmp(Command,"_LCD_RETURN_HOME") == 0){cmnd = 0x80;}
	else if (strcmp(Command,"_LCD_CURSOR_OFF") == 0){cmnd = 0x0A;}
	else if (strcmp(Command,"_LCD_BLINK_CURSOR_ON") == 0){cmnd = 0x0E;}
	else if (strcmp(Command,"_LCD_MOVE_CURSOR_LEFT") == 0){cmnd = 0x10;}
	else if (strcmp(Command,"_LCD_MOVE_CURSOR_RIGHT") == 0){cmnd = 0x14;}
	else if (strcmp(Command,"_LCD_TURN_ON") == 0){cmnd = 0x0A;}
	else if (strcmp(Command,"_LCD_TURN_OFF") == 0){cmnd = 0x08;}
	else if (strcmp(Command,"_LCD_SHIFT_LEFT") == 0){cmnd = 0x18;}
	else if (strcmp(Command,"_LCD_SHIFT_RIGHT") == 0){cmnd = 0x1C;}
	//else    {cmnd = Command;}
	Lcd_Cmd(cmnd);	
	
}

void Lcd_Init (void)			/* LCD Initialize function */
{
	LCD_Command_Dir = 0xFF;		/* Make LCD command port direction as o/p */
	LCD_Data_Dir = 0xFF;		/* Make LCD data port direction as o/p */
	_delay_ms(20);			/* LCD Power ON delay always >15ms */
	
	Lcd_Cmd (0x38);		/* Initialization of 16X2 LCD in 8bit mode */
	Lcd_Cmd (0x0C);		/* Display ON Cursor OFF */
	Lcd_Cmd (0x06);		/* Auto Increment cursor */
	Lcd_Cmd (0x01);		/* clear display */
	_delay_ms(2);			/* Clear display command delay> 1.63 ms */
	Lcd_Cmd (0x80);		/* Cursor at home position */
	Lcd_Out(0,0," ");
}

void Lcd_Chr(unsigned char char_data)  /* LCD data write function */
{
	LCD_Data_Port= char_data;
	LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
	LCD_Command_Port &= ~(1<<RW);	/* RW=0 write operation */
	LCD_Command_Port |= (1<<EN);	/* Enable Pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(2);			/* Data write delay */
}

void Lcd_Out_Cp(char *str)		/* Send string to LCD function */
{
	for(int i = 0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		Lcd_Chr(str[i]);
	}
}

void Lcd_Out(char row, char pos, char *str)  /* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	Lcd_Cmd((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	Lcd_Cmd((pos & 0x0F)|0xC0);	/* Command of sec row and required position<16 */
	Lcd_Out_Cp(str);		/* Call LCD string function */
}

void Lcd_Clear()
{
	Lcd_Cmd (0x0C);		/* Display ON Cursor OFF */
	Lcd_Cmd (0x06);		/* Auto Increment cursor */
	Lcd_Cmd (0x01);		/* clear display */
	_delay_ms(2);			/* Clear display command delay> 1.63 ms */
	Lcd_Cmd (0x80);		/* Cursor at home position */
	Lcd_Out(0,0," ");
}

void Lcd_Custom_Char (unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc<8)
	{
		Lcd_Cmd (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		Lcd_Chr(msg[i]);
	}
}

void Lcd_Custom_Out(char row, char pos,char loc)  /* Send Custom char to LCD with xy position */
{
	if (row == 0 && pos<16)
	Lcd_Cmd((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	Lcd_Cmd((pos & 0x0F)|0xC0);	/* Command of sec row and required position<16 */
	Lcd_Chr(loc);		
}