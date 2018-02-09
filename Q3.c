#include<lpc21xx.h>
void main()
{
IO0DIR=0xffffffff;
while(1)
{
if(IO1PIN&(1<<20))
IO0PIN=0x0000ffff;
else
IO0PIN=0xffff0000;
}
}