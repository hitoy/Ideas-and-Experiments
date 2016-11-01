#include <stdio.h>
/*
 * 题目：宏#define命令练习3。
 */
#define LAG >
#define SAM <
#define EQ ==

int main(){
    int i ,j;
    printf("please input two numbers:");
    scanf("%d %d",&i,&j);
    if (i LAG j)
        printf("%d > %d \n",i,j);
    else if(i EQ j)
        printf("%d = %d \n",i,j);
    else if(i SAM j)
        printf("%d < %d \n",i,j);
    else
        printf("NaN");
    return 0;
}
