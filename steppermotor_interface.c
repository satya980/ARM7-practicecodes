#include<lpc21xx.h>
void delay()
{
unsigned int x,e;
for(x=0;x<60000;x++)
for(e=0;e<30;e++);
}
void main()
{
IO0DIR=(1<<1)|(1<<2)|(1<<3)|(1<<4);
while(1)
{
if(IO0PIN&(1<<7))
{
IO0SET=(1<<3)|(1<<2);
IO0CLR=(1<<4)|(1<<1);
delay();
IO0SET=(1<<2)|(1<<1);
IO0CLR=(1<<3)|(1<<4);
delay();
IO0SET=(1<<1)|(1<<4);
IO0CLR=(1<<3)|(1<<2);
delay();
IO0SET=(1<<3)|(1<<4);
IO0CLR=(1<<1)|(1<<2);
delay();

}
else
{
IO0SET=(1<<3)|(1<<2);
IO0CLR=(1<<4)|(1<<1);
delay();
IO0SET=(1<<4)|(1<<3);
IO0CLR=(1<<1)|(1<<2);
delay();
IO0SET=(1<<1)|(1<<4);
IO0CLR=(1<<3)|(1<<2);
delay();
IO0SET=(1<<1)|(1<<2);
IO0CLR=(1<<3)|(1<<4);
delay();
}
}
}