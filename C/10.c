#include <stdio.h>
/*
 * 题目：打印楼梯，同时在楼梯上方打印两个笑脸。
 */
int main(){
    int i,j;
    printf("\1\1\n");    
    for(i=1;i<10;i++){
        for(j=1;j<i+1;j++){
            printf("|-|");
        }
        printf("\n");
    }
}
