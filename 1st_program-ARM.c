#include<lpc21xx.h>
#define BIT(x) (1<<x)
void main()
{
IO0DIR |= BIT(31);
 while(1)
 {
 if(IO0PIN & BIT(7))
 IO0SET|=BIT(31);
 else
 IO0CLR=BIT(31);
 }
}