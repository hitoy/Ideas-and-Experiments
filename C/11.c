#include <stdio.h>
#include <stdlib.h>
/*
 * 题目：古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）
 */
int main(int argc,char ** argv){
    if(argc==1) 
        printf("Your Must Input Time\n");
        return 0;

    int month = argv[1];
    if(month > 40) month = 40;
    
    int rabbitcount;
}
