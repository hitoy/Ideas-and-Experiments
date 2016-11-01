#include <stdio.h>
/*
 * 宏#define命令练习。
 */
#define TRUE 1
#define FALSE 0
#define SQ(x) (x)*(x)

int main(){

    int num;
    int again = 1;
    printf("If num lt 50, progam will termianl\n");
    while(again){
        printf("please input a number:");
        scanf("%d",&num);
        printf("%d*%d=%d",num,num,SQ(num));
        if(num >= 50)
            again = TRUE;
        else
            again = FALSE;
    
    }
    return 0;
}
