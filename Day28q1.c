#include<lpc21xx.h>
#define prescale 60000
#define plock 0x00000400
void del(unsigned int m)
{
T0TC=0;
T0TCR=0x01;
while(T0TC<m);
T0TCR=0;
}
void main()
{
PLLCON=0x03;
PLLCFG=0x04	;
PLLFEED=0xaa;
PLLFEED=0x55;
while(!(PLLSTAT & plock));
VPBDIV=0x01;
T0PR=prescale-1;
IO0DIR=1<<5;
while(1)
{
IO0SET=1<<5;
del(500);
IO0CLR=1<<5;
del(500);
}
}