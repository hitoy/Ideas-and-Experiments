#include <stdio.h>
/*
 * 题目：学习使用static的另一用法。
 */
int main(){
    int i,sum;
    int num = 2;
    for(i=0;i<3;i++){
        printf("num = %d \n",num);   
        num++;
        {
            static int num = 1;   
            printf("Inner num = %d\n",num);
            num++;
        } 
    }
}
