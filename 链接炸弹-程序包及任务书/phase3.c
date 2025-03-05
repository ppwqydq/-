#include <stdio.h>
void do_phase(int);

static void myfunc(int offset)
{
	printf("gate 3: offset is : %d!\n",offset);
}


void (*phase)(int pos)=do_phase;   // 定义了一个函数指针

void do_phase(int pos)
{
   /* myfunc(pos); */
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
}
