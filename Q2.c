#include<lpc21xx.h>
void del()
{
unsigned int x,y;
for(x=0;x<65000;x++)
for(y=0;y<100;y++);
}
void main()
{PINSEL0=0;
PINSEL1=0;
IO0DIR=0xffffffff;
IO0PIN=0X80000000;

while(1)
{
IO0PIN=IO0PIN>>1;
del();
if(IO0PIN==0x00000001)
{
IO0PIN=0X80000000;
del();
}}
}