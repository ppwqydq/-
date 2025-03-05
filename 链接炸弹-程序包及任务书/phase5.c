#include <stdio.h>

char classname[20]="Computer Foundation";
char teachername[20]="Xu Xiangyang";
char originalclass[20]="c programming";
char originalteacher[20]="ma"; 

void do_phase(int);

void (*phase)(int pos)=do_phase;   // 定义了一个函数指针

void do_phase(int pos)
{
   printf("Class Name %s\n",originalclass); 
   printf("Teacher Name %s\n",originalteacher);
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
