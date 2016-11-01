#include <stdio.h>
/*
 * 题目：学习使用按位取反~。
 */
int main(){
    int a,b;
    a=234;
    b=~a;
    printf("~a=%d\n",b);
    a=~a;
    printf("~~a = %x\n",a);
    return 0;
}
