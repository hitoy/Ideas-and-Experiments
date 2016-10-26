#include <stdio.h>
#include <stdlib.h>
/*
 * 题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
 */
int main(int argc,char **argv){
    if(argc == 1){
        printf("Please Input A Number > 0\n");
        return 0;
    }

    int num = atoi(argv[1]);
    printf("%d=",num);
    int i = 2;
    for(i;i<=num;i++){
        while(num%i==0){
            printf("%d",i);
            num = num/i;
            if(num!=1) printf("*");
        }
    }
    return 0;
}
