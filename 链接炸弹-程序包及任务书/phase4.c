#include <stdio.h>
void do_phase(int);

   static void myfunc(char *s)
{
	printf("gate 4: your ID is : %s!\n",s);
}


void (*phase)(int pos)=do_phase;   // 定义了一个函数指针

void do_phase(int pos)
{
   char  temp[11]="U202212345"; 
   /* myfunc(temp);  */
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
