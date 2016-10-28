#include <stdio.h>
#include <string.h>
/*
 * 题目：字符串反转，如将字符串 "www.runoob.com" 反转为 "moc.boonur.www"。
 */
char* reverse(char* str);
int main(){
    char *str;
    printf("Please Input A string:\n");
    scanf("%s",str);
    printf("%s",reverse(str));
    return 0;
}

char* reverse(char* str){
    int len = strlen(str);
    int zerostart = 0;
    int halfstart = len/2;
    char tmp;
    //空间换时间方法最好，减少IO
    while(zerostart < halfstart){
        tmp = *(str+len-1-zerostart);
        *(str+len-1-zerostart)  = *(str+zerostart);
        *(str+zerostart) = tmp;
        zerostart++;
    }
    return str;
}
