#include <stdio.h>
/*
 * 题目：学习使用auto定义变量的用法。
 */
int main(){
    int i = 1,j = 2,k =3;
    printf("i = %d\n",i);
    printf("j = %d\n",j);
    printf("k = %d\n",k);
    {
    auto int j = 2;
    for(i;i<10;i++){
        printf(" auto j is %d\n",j);
        j++;
    }
    }
    printf("j = %d\n",j);
    return 0;
}
