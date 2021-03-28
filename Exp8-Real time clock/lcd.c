#include<reg51.h>
#include "lcd.h"
#include "delay.h"
#define dataport P1       // LCD dataport connected to PORT1
sbit rs= P3^5;      // Register select pin connected to P3.5
sbit rw= P3^6;      // Read Write pin connected to P3.6
sbit en= P3^7;      // Enable pin connected to P3.7
/* 16x2 lcd Specification */
#define LCDMaxLines 2
#define LCDMaxChars 16
#define LineOne 0x80
#define LineTwo 0xc0 
#define BlankSpace ' '
//LCD initilization
void LCD_Init()
{
delay_ms(15);
lcd_WriteCmd(0x38);
lcd_WriteCmd(0x01);
lcd_WriteCmd(0x10);
lcd_WriteCmd(0x0c);
lcd_WriteCmd(0x80);
}
 
 
// lcd Write command function
void lcd_WriteCmd( char a)
{
   dataport=a;        
   rs=0;                      
   rw=0;                 
 	 en=1;                 
   delay_us(1);
   en=0;
   delay_us(200);                  
}
 
 
 // lcd writedata function
void lcd_Writedata( char a)
{
   dataport=a;        
     rs=1;                      
     rw=0;                      
     en=1;                      
    delay_us(1);
     en=0;
   delay_us(200);                
}

 
 //lcd gotolinetwo fuction
void lcd_Line_posnY()
{
   lcd_WriteCmd(LineTwo);   // move the Cursor to Second line First Position
}
 
 
 
//lcd go to X(first row), Y(second row) line
void lcd_curser_posn(char row, char col)
{
   char pos;
 
    if(row<LCDMaxLines)
      {
         pos= LineOne | (row << 6);
                                    
 
        if(col<LCDMaxChars)
           pos= pos+col;            
                                    
 
         lcd_WriteCmd(pos);        
       }
}
 

//lcd display string function
void lcd_DisplayString(char *string_ptr)
{
   while(*string_ptr)
    lcd_Writedata(*string_ptr++);
    }
 
 
//lcd display rtc time function
void lcd_DisplayRtcTime(char hour,char min,char sec)
{
    lcd_Writedata(((hour>>4) & 0x0f) + 0x30);
    lcd_Writedata((hour & 0x0f) + 0x30);
    lcd_Writedata(':');
    lcd_Writedata(((min>>4) & 0x0f) + 0x30);
    lcd_Writedata((min & 0x0f) + 0x30);
    lcd_Writedata(':');
    lcd_Writedata(((sec>>4) & 0x0f) + 0x30);
    lcd_Writedata((sec & 0x0f) + 0x30);
 }
 
 
 // lcd display rtc date function
void lcd_DisplayRtcDate(char day,char month,char year)
 {
     lcd_Writedata(((day>>4) & 0x0f) + 0x30);
     lcd_Writedata((day & 0x0f) + 0x30);
     lcd_Writedata('/');
     lcd_Writedata(((month>>4) & 0x0f) + 0x30);
     lcd_Writedata((month & 0x0f) + 0x30);
     lcd_Writedata('/');
     lcd_Writedata(((year>>4) & 0x0f) + 0x30);
     lcd_Writedata((year & 0x0f) + 0x30);
 }

 void lcd_Clear()
{
    lcd_WriteCmd(0x01);
}
 