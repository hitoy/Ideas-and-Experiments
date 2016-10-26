#include <stdio.h>
#include "math.h"
/*
 *题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
 */
int main(){
    int i,j,tmp,sum=0;
    printf("Input Number and size:");
    scanf("%d %d",&i,&j);
    for(j;j>0;j--){
        sum += getnum(i,j);
    }
    printf("a+aa+aaa=%d\n",sum);
    return 0;
}

int getnum(int num,int len){
    int sum = 0;
    while(len>0){
        sum = sum + num*pow(10,(len-1));
        len--;
    }
    return sum;
}
