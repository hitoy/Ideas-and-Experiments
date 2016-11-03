#include <stdio.h>
/*
 * 题目：有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来第几号的那位。
 */
int main(){
    int i=1,num;
    printf("Please Input number of people:");
    scanf("%d",&num);
    char list[num];
    while(1){
        if(num==1) break;
        if(i==num) i = 1;
        if(i%3==0){
            num--;
        }
        i++;
    }
}
