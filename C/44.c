#include <stdio.h>
/*
 * 题目：学习使用external的用法。
 */
void add()
{
    int a,b,c;
    a=3;
    c=a+b;
}
int main()
{
    a=b=4;
    extern c;
    add();
    printf("c  = %d\n",c);
    return 0;
}
