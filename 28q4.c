#include<lpc21xx.h>
#define prescale 60000
#define plock 0x00000400
void del0(unsigned int m)
{
T0TC=0;
T0TCR=0x01;
while(T0TC<m);
T0TCR=0;
}
void del1(unsigned int m)
{
	  T1TC=0;
T1TCR=0x01;
while(T1TC<m);
T1TCR=0;
}
void main()
{
 PLLCON=0x03;
PLLCFG=0x04;
PLLFEED=0xaa;
PLLFEED=0x55;
while(!(PLLSTAT&plock));
VPBDIV=0x01;
T1PR=prescale-1;
T0PR=prescale-1;
 IO1DIR=1<<28; 
  while(1)
  {
  if(IO0PIN&(1<<28))
  {
  IO1SET=1<<28;
  del0(400);
  IO1CLR=1<<28;
  del0(400);
  }
  else
  {
  	IO1SET=1<<28;
  del1(800);
  IO1CLR=1<<28;
  del1(800);
  }
  }
}