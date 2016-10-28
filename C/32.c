#include <stdio.h>
#include <string.h>

char* deletechar(char *string,char del);
/*
 * 题目：删除一个字符串中的指定字母，如：字符串 "aca"，删除其中的 a 字母。
 */
int main(){
    char *s,d;
    printf("Please Input A Strings:");
    scanf("%s",s);
    printf("%s\n",s);
    getchar();
    printf("Please INput A Letter you want ot delete from the string you input:");
    d = getchar();
    getchar();
    printf("Target String is %s\n",deletechar(s,d));
    return 0;
}

char* deletechar(char *string,char del){
    int len,i,j;
    char current,next;
    len = strlen(string);
    i = 0,j=0;
    char *newstring;
    while(i<len){
        if(string[i] != del){
            newstring[j] = string[i];
            j++;
        }
        i++;
    }
    printf("string len %d,newstring len %d\n",len,strlen(newstring));
    return newstring;
}
