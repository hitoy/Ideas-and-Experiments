#include <stdio.h>
/*
 *题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
 * 错误点：如果这里i，和j为int类型，则最后求和会出现问题
 */

int main(){
    float sum = 0,i=2,j=1,t;
    int k = 1;
    while(k<=20){
        printf("Element:%d SUM: %f/%f\n",k,i,j);
        sum = sum + i/j;
        t = i;
        i = i+ j;
        j = t;
        k++;
    }
    printf("SUM iS %9.6f\n",sum);
}
