#include <stdio.h>
/*
 * 题目：一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。
 */
int main(){
    int num;
    printf("Pleas Input A Number:");
    scanf("%d",&num);
    
    if(num/10000 == num%10 && num%10000/1000 == num%100/10){
        printf("YES\n");
    }else{
        printf("No\n");
    }
    return 0;
}
