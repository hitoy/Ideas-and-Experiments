#include <stdio.h>
/*
 * 题目：取一个整数a从右端开始的4～7位。
 * ~:取反优先级较移位高
 */
int main(){
    unsigned int a,b,c,d;
    printf("Pleae Input A numBer:");
    scanf("%d",&a);
    b = a>>4;
    printf("b is %d\n",b);
    c = ~(0<<4);
    d = b & c;
    printf("a = %d d = %d\n",a,d);
    return 0;
}
