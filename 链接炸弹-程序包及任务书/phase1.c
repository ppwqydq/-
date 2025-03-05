#include <stdio.h>
void do_phase(int);

char buf[30]="abcdefghijklmnopqrstuvwxyz";

void (*phase)(int pos)=do_phase;   // 定义了一个函数指针

void do_phase(int pos)
{
     printf("your ID is : %s\n",buf+pos);
}
