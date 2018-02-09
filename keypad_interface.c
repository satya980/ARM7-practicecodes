#include<lpc21xx.h>
int row[]={0xfe,0xfd,0xfb,0xf7};
int col[]={0xef,0xdf,0xbf,0x7f};
int key[]={0,1,2,3,4,5,6,7,8,9,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};
unsigned int a,b,c;
void del()
{
unsigned int u,x;
for(u=0;u<65535;u++)
for(x=0;x<100;x++);
}
void main()
{
IO1DIR|=0xffffffff;
IO0DIR|=0xFFFFFFFF;
PINSEL0=PINSEL1=PINSEL2=0;
while(1)
{
//l:IO0PIN=0xf0;
//while(IO0PIN==0xf0)
//{
//IO0DIR=0x00;
//}
IO0PIN=0;
a=0;
for(b=0;b<4;b++)
{
IO0PIN=row[b];
for(c=0;c<4;c++)
{
if((IO0PIN|0x0f)==col[c])
{
IO1PIN=key[a]<<16;	del();
//goto l;
}
else
a=a+1;
}
}
}
}