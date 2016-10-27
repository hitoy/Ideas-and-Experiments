#include <stdio.h>
/*
 * 题目：给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
 */
int main(){
    int a,b,c,d,e,input;
    printf("Please Input Names:");
    scanf("%d",&input);
    a = input/10000;
    b = input%10000/1000;
    c = input%1000/100;
    d = input%100/10;
    e = input%10;
    if (a!=0){
        printf("为 5 位数,逆序为： %d %d %d %d %d\n",e,d,c,b,a);
    } else if(b!=0) {
         printf("为 4 位数,逆序为： %d %d %d %d\n",e,d,c,b);
    } else if(c!=0) {
         printf("为 3 位数,逆序为：%d %d %d\n",e,d,c);
    } else if(d!=0) {
         printf("为 2 位数,逆序为： %d %d\n",e,d);
    } else if(e!=0) {
         printf("为 1 位数,逆序为：%d\n",e);
    }
    return 0;
}
