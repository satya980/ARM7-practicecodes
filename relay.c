#include<lpc21xx.h>
void main()
{	  while(1)
{
IO0DIR=1<<5;
if(IO0PIN&(1<<1))
IO0SET=1<<5;
else
IO0CLR=1<<5;
}
}
