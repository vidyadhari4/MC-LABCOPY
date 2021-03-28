
#include <reg51.h>
#include <stdio.h>

sbit sc = P2^0;
sbit eoc = P2^1;
sbit ale = P3^4;
sbit oe = P3^0;
sbit addr_a = P3^7;
sbit addr_b = P3^6;
sbit addr_c = P3^5;

void main(void)
 { 
   P0 = 0xff;
   P2 = 0x02;
   while (1)
   {
      addr_a = 0;
      addr_b = 0;
      addr_c = 0;
      ale = 1;
      sc =1;
      ale = 0;
      sc = 0;
      while(eoc == 1);
      while(eoc == 0);
      oe = 1;
      P1 = P0;
      oe = 0;
   }
 }