#include <stdio.h>
void do_phase(int);

void (*phase)(int pos)=do_phase;   // 定义了一个函数指针

void do_phase(int pos)
{
   printf("U202212345\n");
}
