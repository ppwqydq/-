#include <stdio.h>
void do_phase(int);

static void myfunc()
{
	printf("myfunc is called. Good!\n");
}


void (*phase)(int pos)=do_phase;   // 定义了一个函数指针

void do_phase(int pos)
{
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
