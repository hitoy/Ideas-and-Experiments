#include <stdio.h>
/*
 * 题目：学习使用按位异或 ^。
 */
int main(){
    int a,b;
    a=077;//111111
    b=a^3;// 111111 ^ 11 = 111100 = 63 - 3 = 60
    printf("b = %d\n",b); 
    b^=7; //111100 ^ 111 = 111011 = 60 - 1 = 59
    printf("b = %d\n",b);
    return 0;
}

/*
 * 按位与，或，异或
 * 与：1&1=1 else:0
 * 或: 1|1=1 1|0=1 else:0
 * 异或: 1^0=1 else:0
 * 11 ^ 10 = 01 01 ^ 10 = 11
 */
