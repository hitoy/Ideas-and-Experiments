#include <stdio.h>
/*
 * 题目：学习使用按位或 |。
 */
int main(){
    int a,b;
    a = 077;//八进制数 077 = 63 = 16*3+15 = 0x3f = 111111
    b = a | 3; //111111 | 11
    printf("b = %d\n",b); //111111 = 77
    b|=7; //111111 | 111
    printf("b = %d\n",b);
    return 0;
}
