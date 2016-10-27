#include <stdio.h>
#include <stdlib.h>
/*
 * 题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。
 */
/*
 * 知识点:
 * 如果定义或者对比单个字符，需要用单引号
 */
int main(){
    int i = 0;
    char str[5];
    char s;
    while(i<5){
        s = getchar();
        if(s !='\n'){
            printf("Char %c,code %d i %d\n",s,s,i);
            str[i] = s;
            i++;
        }
    }
    OutputChar(&str,5);
    return 0;
}

void OutputChar(char *str,int len){
    if(len = 1){
        putchar(str[0]);
    }else{
        putchar(str[len-1]);
        OutpuChar(*str,len-1);
    }
}
