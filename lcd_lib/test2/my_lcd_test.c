#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include "my_lcd.h"

void custom_build(void);
void print(void);

int main(void)
{	
	
	Lcd_Init();
	Lcd_Clear();
	Lcd_Out(0,0,"AVR LCD library");
	_delay_ms(1000);
	Lcd_Clear();
	_delay_ms(250);
    while (1) 
    {
	print();
	_delay_ms(1000);
	Lcd_Clear();
	_delay_ms(250);
    }
}


//function to define then build custom characters "10,11,12,13,14,15,16" charsracters
void custom_build(void){
	
	unsigned char Character10[8] = { 0x17,0x15,0x15,0x15,0x15,0x15,0x17,0x00 };  /* Custom char set for alphanumeric LCD Module */
	unsigned char Character11[8] = { 0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x00 };
	unsigned char Character12[8] = { 0x17,0x11,0x11,0x17,0x14,0x14,0x17,0x00 };
	unsigned char Character13[8] = { 0x17,0x11,0x11,0x17,0x11,0x11,0x17,0x00 };
	unsigned char Character14[8] = { 0x15,0x15,0x15,0x17,0x11,0x11,0x11,0x00 };
	unsigned char Character15[8] = { 0x17,0x14,0x14,0x17,0x11,0x11,0x17,0x00 };
	unsigned char Character16[8] = { 0x17,0x14,0x14,0x17,0x15,0x15,0x17,0x00 };
    Lcd_Init();
	Lcd_Custom_Char(0, Character10);  /* Build Character1 at position 0 */
	Lcd_Custom_Char(1, Character11);  /* Build Character2 at position 1 */
	Lcd_Custom_Char(2, Character12);  /* Build Character3 at position 2 */
	Lcd_Custom_Char(3, Character13);  /* Build Character4 at position 3 */
	Lcd_Custom_Char(4, Character14);  /* Build Character5 at position 4 */
	Lcd_Custom_Char(5, Character15);  /* Build Character6 at position 5 */
	Lcd_Custom_Char(6, Character16);  /* Build Character6 at position 6 */
}

//function to print from 1 to 16 on lcd
void print(void){
	custom_build();
	char i,j;
	for (i=0;i<2;i++)
	{
		char s;
		for (j=1;j<10;j++)
		{
		s = itoa(j,s,10);	
		Lcd_Out(i,j-1,s);
		_delay_ms(50);
			
		}
		for (j=9;j<17;j++)
		{
		Lcd_Custom_Out(i,j,j-9);
		_delay_ms(50);	
		}
	}
}



