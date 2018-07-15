# AVR LCD LIBrary 
made by / Muhammad Magdy with help of "http://www.electronicwings.com"


## first add library files into project 
* add>>existing item
* choose my_lcd.c and my_lcd.h
* include "my_lcd.h" into your main c file 
* enjoy
----------------------------------------------------
## electrical wiring

* D0 -- B0 
* D1 -- B1
* D2 -- B2
* D3 -- B3
* D4 -- B4
* D5 -- B5
* D6 -- B6
* D7 -- B7

* RS -- C0
* RW -- C1
* E  -- C2

----------------------------------------------------
##main functions

*Lcd_Cmd();
*Lcd_Command();
*Lcd_Init();
*Lcd_Chr();
*Lcd_Out_Cp();
*Lcd_Out();
*Lcd_Clear();
*Lcd_Custom_Char();
*Lcd_Custom_Out();

----------------------------------------------------
##function of imbortant functions 

*Lcd_Init(); >>>>> Initializes Lcd module in 8-bit mode.
ex           >>>>> Lcd_Init();
-----------------------------------

*Lcd_Out();  >>>>> Prints text on Lcd starting from specified position.
ex           >>>>> Lcd_Out(0,0,"hi"); //print ho on row 0 col 0.
-----------------------------------

*Lcd_Clear(); >>>>> clear display.
ex            >>>>> Lcd_Clear();
-----------------------------------

*Lcd_Command(); >>>>> Sends command to Lcd.
ex
Lcd_Command("_LCD_CLEAR ");  //Clear display

Lcd_Command("_LCD_RETURN_HOME "); //Return cursor to home position, returns a shifted display to its original position.

Lcd_Command("_LCD_CURSOR_OFF"); //Turn off cursor

Lcd_Command("_LCD_BLINK_CURSOR_ON"); //Blink cursor on

Lcd_Command("_LCD_MOVE_CURSOR_LEFT"); //Move cursor left without changing display data RAM

Lcd_Command("_LCD_MOVE_CURSOR_RIGHT"); //Move cursor right without changing display data RAM

Lcd_Command("_LCD_TURN_ON");//Turn Lcd display on

Lcd_Command("_LCD_TURN_OFF");//Turn Lcd display off

Lcd_Command("_LCD_SHIFT_LEFT");//Shift display left without changing display data RAM

Lcd_Command("_LCD_SHIFT_RIGHT");//Shift display right without changing display data RAM
----------------------------------

*Lcd_Custom_Char();   >>>>>  sends Custom Char to memory
ex
unsigned char Character10[8] = { 0x17,0x15,0x15,0x15,0x15,0x15,0x17,0x00 };
Lcd_Custom_Char(0, Character10);  // Build Character at position 0 in memory.
----------------------------------

*Lcd_Custom_Out();    >>>>>  print Custom Char at wanted position
ex
unsigned char Character10[8] = { 0x17,0x15,0x15,0x15,0x15,0x15,0x17,0x00 };
Lcd_Custom_Char(0, Character10);  
Lcd_Custom_Out(1,2,0);    //prints Custom Char at 0 memory location at 2nd row 3rd col





