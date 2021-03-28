
 
#include<reg51.h>
#include<intrins.h>
#include "delay.h" 
 
/*void delay_us(unsigned int us_count)
 {  
    while(us_count!=0)
      {
         us_count--;
       }
   }*/
void delay_us(unsigned int us_count)
{
    while(us_count!=0)
		{
			_nop_();  //it takes one microsecond
			us_count--;
		}			
}
/* void delay_ms(int k)
{
		int i;
	TMOD=0X02;
	TH0=0x00;
	while(k!=0)
	{
		for(i=0;i<4;i++){
		TR0=1;
		while(!TF0);
		TF0=0;}
		k--;
	}
}  */
void delay_ms(int a)//assuming 12 MhZ clock for Timer in Mode 1, it is 1ms delay...pass a= 1000 for 1 sec delay
   {
     int i;
     TMOD = 0x01;      // Timer0 mode1
            for(i=0;i<a;i++)
                {
               TH0=0xFC;              //initial values for 1 milli second delay
                TL0=0x18;
                TR0 = 1;               // timer0 start
            while (TF0 == 0);   // check overflow condition
                TR0 = 0;               // Stop Timer
                TF0 = 0;               // Clear overflow flag
              }
}