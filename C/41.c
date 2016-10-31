#include <stdio.h>
/*
 *学习static定义静态变量的用法。
 */
void func();
int main(){
    int i = 0;
    while(i<10){
        func();
        i++;
    }
    return 0;
}

void func(){
    static int static_i = 1;
    int i = 0;
    printf("i=%d\n",i);
    printf("static_i=%d\n",static_i);
    i++;
    static_i++;
}
