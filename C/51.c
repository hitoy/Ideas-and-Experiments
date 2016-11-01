#include <stdio.h>
/*
 * 题目：学习使用按位与 &。
 */
int main(){
    int a,b;
    a = 077;//0 开头是8进制数 077 = 63 = 64-1 = 2**6 -1 = 1000000 -1 = 111111
    b = a&3;//11111 & 11
    printf("a & b(decimal) = %d \n",b);
    b&=7;//11 & 111
    printf("a & b(decimal) = %d \n",b);
    return 0;
}
