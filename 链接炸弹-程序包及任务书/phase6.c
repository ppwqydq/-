#include <stdio.h>

void do_phase(int);

void (*phase)(int pos)=do_phase;   // 定义了一个函数指针
void (*myprint)();

void do_phase(int pos)
{
     if (myprint) {
         (*myprint)();
     }
     else {
          printf("please write phase6_patch.c \n");
     }
}
