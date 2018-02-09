#include<lpc21xx.h>
void del()
{
int x;
for(x=0;x<6000;x++);
}
void main()
{
IO1DIR=0xffffffff;
IO1PIN=0xffffffff;
while(1)
{
IO1PIN=~IO1PIN;
del();
}

}