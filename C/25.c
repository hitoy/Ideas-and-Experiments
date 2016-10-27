#include <stdio.h>
/*
 * 题目：求1+2!+3!+...+20!的和。
 */

int main(){
    int n = 20;
    int sum;
    while(n>0){
        sum += fact(n);
        n--;
    }
    printf("result is %d\n",sum);
}

int fact(int n)
{
         int pro;//pro,即product,乘积，
         if(n<=1)
                   pro=1;
         else
                   pro=n*fact(n-1);
         return(pro);
}
