#include <stdio.h>
/*
 *题目：学习使用register定义变量的方法。
 */
/*
 * register 寄存器变量，请求编译器将这个变量保存在CPU的寄存器中，从而加快程序的运行.
 */
int main(){
   register int i; 
   int tmp = 0 ;
   for(i = 0 ; i <= 100; i++){
        tmp = tmp +i;
   }
    printf("1+2+3+...+100=%d\n",tmp);
    return 0;
}
