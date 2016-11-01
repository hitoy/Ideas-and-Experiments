#include <stdio.h>
#include <math.h>
/*
 * 题目：打印出杨辉三角形（要求打印出10行）。
 */
int main(){
    unsigned int lines;
    printf("Please Input Lines you want to print:");
    scanf("%d",&lines);
    if(lines>pow(2,sizeof(long)*8)){
        printf("The lines too large");
        return 1;
    }
    //用一个长数组存放第N行的杨辉三角的数字
    long int hui[lines];
    int n = 1,i;
    while(n<=lines){
        //第一个和最后一个永远是1
        hui[0] = 1;
        hui[n-1] = 1;
        //第N个杨辉三角遍历
        for(i=n-1;i>=0;i--){
            if(i>0 && i < n-1){
                hui[i] = hui[i] + hui[i-1];
            }
        }
        for(i=0;i<n;i++){
            printf("%ld ",hui[i]);
        }
        printf("\n");
        n++;
    }
}
