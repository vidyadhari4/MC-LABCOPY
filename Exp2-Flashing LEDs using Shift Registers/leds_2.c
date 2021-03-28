
#include<reg51.h>
void delay(int a);
sbit led1= P2^0;
sbit led2= P2^1;
sbit led3= P2^2;
sbit led4= P2^3;
sbit led5= P2^4;
sbit led6= P2^5;
sbit led7= P2^6;
sbit led8= P2^7;
int main(void)
{
	P2=0x00;
	while(1)
	{
		led1=0;
		led2=1;
		led3=0;
		led4=1;
		led5=0;
		led6=1;
		led7=0;
		led8=1;
		delay(100);
		led1=1;
		led2=0;
		led3=1;
		led4=0;
		led5=1;
		led6=0;
		led7=1;
		led8=0;
		delay(100);
	}
}
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<1000;j++)
		{
		}
	}
}