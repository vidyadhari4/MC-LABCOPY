#include <reg51.h>
//sbit w1 = P1^0;
//sbit w2 = P1^1;
//sbit w3 = P1^2;
//sbit w4 = P1^3;

void main(void)
 { 
   unsigned int i;
   //w1=w2=w3=w4=0; 
	 P2= 0x00;
   while (1)
     {
			 //for wave mode(90')
//			 P2 = 0x08;
//			 for(i=0;i<60000;i++);
//			 P2 = 0x02;
//			 for(i=0;i<60000;i++);
//			 P2 = 0x04;
//			 for(i=0;i<60000;i++);
//			 P2 = 0x01;
//			 for(i=0;i<60000;i++);
			// For half step (45')
			 P2 = 0x01;
			 for(i=0;i<60000;i++);
			 P2 = 0x05;
			 for(i=0;i<60000;i++);
			 P2 = 0x04;
			 for(i=0;i<60000;i++);
			 P2 = 0x06;
			 for(i=0;i<60000;i++);
			 P2 = 0x02;
			 for(i=0;i<60000;i++);
			 P2 = 0x0A;
			 for(i=0;i<60000;i++);
			 P2 = 0x08;
			 for(i=0;i<60000;i++);
			 P2 = 0x09;
			 for(i=0;i<60000;i++);
      // For Full step 
//			  P2 = 0x09;
//			 for(i=0;i<60000;i++);
//			 P2 = 0x05;
//			 for(i=0;i<60000;i++);
//			 P2 = 0x06;
//			 for(i=0;i<60000;i++);
//			 P2 = 0x0A;
//			 for(i=0;i<60000;i++);
//      w1 = 1;
//      w2=w3=w4=0;
//      for(i=0;i<60000;i++);
//      w2=1;
//      w1=w3=w4=0;   
//      for(i=0;i<60000;i++);
//      w3=1;
//      w1=w2=w4=0;  
//      for(i=0;i<60000;i++);
//      w4=1;
//      w1=w2=w3=0;
//      for(i=0;i<60000;i++);
			
     }
      
 }