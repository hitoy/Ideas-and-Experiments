#include <stdio.h>
#include <stdlib.h>
/*
 * 题目：输入三个整数x,y,z，请把这三个数由小到大输出。
 * 冒泡排序法
 */
int main(int argc,char **argv){
    int i,k,j;
    char* tmp;
    if(argc < 4){
        printf("Input Size to small!\n");
        return 0;
    }
    for(i = 1 ; i < argc ; i++){
        for(k = i; k < argc-i-1; k++){
            if(atoi(argv[k]) > atoi(argv[k+1])){
                tmp = argv[k+1];
                argv[k+1] = argv[k];
                argv[k] = tmp;
            }
        }
    }
    for(j = 1; j < argc; j++){
        printf("%d,%s\n",argc,argv[j]);
    }

}
