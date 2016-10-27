#include <stdio.h>
/*
 *题目：猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个, 第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下?的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。
    设前一条的桃子数量为X1，第二天为X2：则X2 = X1/2-1，推出: X1=(X2+1)*2
 */
int main(){
    int day = 8;
    int sum = 1;
    while(day > 0){
        sum = (sum+1)*2;
        printf("The %d day: %d\n",day, sum);
        day --;
    }
    printf("Total:%d\n",(sum+1)*2);
    return 0;
}
