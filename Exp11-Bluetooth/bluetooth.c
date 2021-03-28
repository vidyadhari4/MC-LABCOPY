//******************************************************************************
//****************Part 1 0f HC-05 module interfacing****************************
//******************************************************************************
#include<regx51.h> 
sbit mot1=P2^0;
sbit mot2=P2^1;
sbit mot3=P2^2;
sbit mot4=P2^3;
void main()
{	
//Initialize serial communication and activate interrupts.
TMOD = 0x20;  // choosing 	Timer mode
TH1 =  0xFD; // Selecting baud rate 9600
SCON =0x50;  // Serial mode selection
TR1 = 1;  // Initializing serial Communication 
IE =0x90; //Enabling Serial Interrupt	
while(1);	
}
void ser_intr(void) interrupt 4        //Subroutine for Interrupt  
{
char c;	
IE=0x00;
while(RI==0);
c=SBUF;	
if(c=='F')                           //Controlling motor
{
mot1=1;
mot2=0;
mot3=0;
mot4=1;	
}
if(c=='R')
{
mot1=0;
mot2=1;
mot3=1;
mot4=0;		
}
if(c=='S')   // For stopping the motor
{
mot1=mot2=mot3=mot4=0;
}
RI = 0;
IE=0x90;
}
//*****************************************************************************
//****************Part 2 0f HC-05 module interfacing***************************
//*****************************************************************************
//#include<regx51.h> 
//sbit mot1=P2^0;
//sbit mot2=P2^1;
//sbit mot3=P2^2;
//sbit mot4=P2^3;

//void main()
//{
//	char c;
////Initialize serial communication and activate interrupts.
//SCON =0x50;  // Serial mode selection
//TMOD = 0x20;  // choosing 	Timer mode
//TH1 =  0xFD; // Selecting baud rate 9600
//TR1 = 1;  // Initialixing serial Communication 
////IE =0x90; //Enabling Serial Interrupt	
//while(1);	
//{
//while(RI==0);
//c=SBUF;
//RI=0;	
//if(c=='F')                           //Controlling motor
//{
//mot1=1;
//mot2=0;
//mot3=0;
//mot4=1;	
//}
//if(c=='R')
//{
//mot1=0;
//mot2=1;
//mot3=1;
//mot4=0;		
//}
//if(c=='S')   // For stopping the motor
//{
//mot1=mot2=mot3=mot4=0;
//}
//}
//}
//******************************************************************
//********************* Part 3 of HC-05 Module communication********
//******************************************************************
//#include<regx51.h>
//#include<stdio.h>
//#include<string.h> 
//int a,b,ans;
//char rec[4];
//void main()   
//{    
//a=80;
//b=40;
//ans=a+b;
//sprintf(rec, "%d", ans);
//TMOD=0x20;                                //Choosing Timer mode    
//TH1=0xFD;                                   //Selecting Baud Rate    
//SCON=0x50;                               //Serial mode selection    
//TR1=1;    
//IE=0x90;                                      //Enabling Serial Interrupt    
//while(1);    
//}
//void ser_intr(void)interrupt 4        //Subroutine for Interrupt  
//{
//IE=0x00;
//short int i;
//for(i=0;i<=2;i++)                      //Transmitting data
//{
//SBUF=rec[i];
//while(TI==0);
//TI=0;
//}
//IE=0x90;
//}