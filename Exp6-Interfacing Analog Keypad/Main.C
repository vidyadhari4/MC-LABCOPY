#include<reg51.h>
#include<stdio.h>
sbit c0=P1^2;
sbit c1=P1^1;
sbit c2=P1^0;
sbit r0=P1^3;
sbit r1=P1^4;
sbit r2=P1^5;
sbit r3=P1^6;
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
sfr lcd_data=0xa0;
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void delay(unsigned int);
void lcd_string(unsigned char*str);
void main()
{
   P2=0x00;
   lcdcmd(0x38);
   lcdcmd(0x0f);
   lcdcmd(0x06);
   lcdcmd(0x01);
   lcdcmd(0x80);
   lcd_string("Try:");
   while(1)
   {
      r0=0,r1=1,r2=1,r3=1;
      if(c0==0)
      {
	 lcddata('1');
      }
      if(c1==0)
      {
	 lcddata('2');
      }
      if(c2==0)
      {
	 lcddata('3');
      }
      r0=1,r1=0;
       if(c0==0)
      {
	 lcddata('4');
      }
      if(c1==0)
      {
	 lcddata('5');
      }
      if(c2==0)
      {
	 lcddata('6');
      }
      r0=1,r1=1,r2=0,r3=1;
       if(c0==0)
      {
	 lcddata('7');
      }
      if(c1==0)
      {
	 lcddata('8');
      }
      if(c2==0)
      {
	 lcddata('9');
      }
       r0=1,r1=1,r2=1,r3=0;
       if(c0==0)
      {
	 lcddata('*');
      }
      if(c1==0)
      {
	 lcddata('0');
      }
      if(c2==0)
      {
	 lcddata('#');
      }
   }
}   
void lcdcmd(unsigned char comd)
   {
      lcd_data=comd;
      rs=0;
      rw=0;
      en=1;
      delay(100);
      en=0;
      delay(200);
   }
void lcddata(unsigned char value)
   {
      lcd_data=value;
      rs=1;
      rw=0;
      en=1;
      delay(100);
      en=0;
      delay(400);
   }
void delay(unsigned int count)
   {
      int i,j;
      for(i=0;i<count;i++)
      for(j=0;j<100;j++);
   }
void lcd_string(unsigned char *str)
   {
      int i;
      int j=0xc0;
      for(i=0;str[i]!='\0';i++)
      {
	 lcddata(str[i]);
	 if(i>=16)
	 {
	    lcdcmd(j);
	    j++;
	 }
      }
   }