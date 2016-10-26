#include <stdio.h>
#include "math.h"
/*
 * 题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
 */
int main(){
    int i = 0;
    int x,y;
    while(1){
        x = sqrt(100+i);
        y = sqrt(268+i);

        if(x*x == i + 100 && y*y == i + 268){
            printf("I is %d\n",i);
        }
        i++;    
    }
}
