#include <stdio.h>
/*
 *题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
 */
int main(){
    int i,k;
    printf("Input to Numbers:");
    scanf("%d,%d",&i,&k);
    int min = i>k?k:i;
    while(min){
        if(i%min == 0 && k%min == 0) break;
        min--;
    }
    printf("%d",min);
}
