#include <stdio.h>
#include <stdlib.h>
/*
 * 题目：输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组。。
 */
int main(){
    int* p = malloc(sizeof(int));
    int num,i=0,maxindex,minindex,max=0,min=0,j,k,tmp=0;
    while(num!=0){
        printf("请输入一个数字,输入0结束输入:");
        scanf("%d",&num);
        if(num==0) break;
        p[i] = num;
        p = realloc(p,sizeof(int)*(i+2));
        i++;
    }
    max = p[0];
    min = p[0];
    maxindex = 0;
    minindex = 0;
    for(j=0;j<i-1;j++){
        if(max < p[j+1]){
            max = p[j+1];
            maxindex = j+1;
        }
        if(min > p[j+1]){
           min = p[j+1];
           minindex = j+1;
        }
    }

    printf("maxinde %d minindex %d\n",maxindex,minindex);
    printf("原数组:\n");
    for(j=0;j<i;j++){
        printf("%d,",p[j]);
    }
    printf("\n调整过:\n");
    
    tmp = p[0];
    p[0] = p[maxindex];
    p[maxindex] = tmp;
    tmp = p[i-1];
    p[i-1] = p[minindex];
    p[minindex] = tmp;

    for(j=0;j<i;j++){
        printf("%d,",p[j]);
    }
    return 0;
}
