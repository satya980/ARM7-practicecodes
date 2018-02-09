#include<lpc21xx.h>
#include<lpc21xx.h>
#define PLOCK 0x00000400
void main()
{        PINSEL0=0X05;
          U0LCR=0X83;
          U0DLL=0X86;
          U0DLM=0X01;
          U0LCR=0X03;
          PLLCON=0X03;
          PLLCFG=0X24;
          PLLFEED=0X55;
          PLLFEED=0XAA;
          while(!(PLLSTAT & PLOCK));
          VPBDIV=0x01;
          while(1)
         {
	        while(!(U0LSR & 0x20));
	        U0THR='x';
        }
}
