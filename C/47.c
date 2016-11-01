#include <stdio.h>
/*
 * 题目：宏#define命令练习2。
 */
#define exchange(a,b) {int t;t=a;a=b;b=t;} //放在一行里面
int main(){
    int x=10;
    int y=20;
    printf("x=%d,y=%d\n",x,y);
    exchange(x,y);
    printf("x=%d,y=%d\n",x,y);
    return 0;
}
