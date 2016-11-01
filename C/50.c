#include <stdio.h>
/*
 * 题目：#include 的应用练习。
 */
#include "test.h"

int main(){
    int i=10;
    int j=20;
    if(i LAG j)
        printf("%d > %d\n",i,j);
    else if(i EQ j)
        printf("%d = %d\n",i,j);
    else if(i SMA j)
        printf("%d < %d\n",i,j);
    else
        printf("NAN");
    return 0;
}
