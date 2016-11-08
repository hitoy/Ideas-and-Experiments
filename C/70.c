#include <stdio.h>
/*
 * 题目：写一个函数，求一个字符串的长度，在main函数中输入字符串，并输出其长度。
 */
int str_len(char *s);

int main()
{
    char *string;
    printf("Please Input strings:");
    scanf("%s",string);
    printf("the length of string is %d",str_len(string));
    return 0;
}

int str_len(char *string){
    int i = 0;
    while(*string!='\0'){
        string++;
        i++;
    }
    return i;
}
