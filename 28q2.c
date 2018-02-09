#include<lpc21xx.h>
#define plock 0x00000400
#define prescale 60000
void del(unsigned int m)
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
 IO1DIR=1<<19;
  while(1)
  {
  IO1SET=1<<19;
  del(800);
  IO1CLR=1<<19;
  del(200);
  }
}