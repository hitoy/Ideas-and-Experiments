#include <stdio.h>
#include <stdlib.h>
/*
 * 题目：输入n个数.....，个数不确定，按大小顺序输出。
 */
int main(){
    int *p = malloc(sizeof(int));
    int i=0,j,k,num,tmp;
    while(num!=0){
        printf("Please Input a Number(Enter 0 to Skip):");   
        scanf("%d",&num);
        if(num==0) break;
        p[i]=num;
        i++;
        p = realloc(p,sizeof(int)*(i+1));
    }
    for(j=0;j<i;j++){
        printf("%d,",p[j]);
    }
    printf("\n");

    //冒泡排序法
    //1，选出最大的一个数，放到最右边
    //2，选出剩下的数字中，最大的一个数字，放到第倒数自二个
    //3，以此类推
    for(k=i-1;k>=0;k--){
        for(j=0;j<k;j++){
            if(p[j]>p[j+1]){
                tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
            }
        }
    }

    for(j=0;j<i;j++){
        printf("%d,",p[j]);
    }
    free(p);
    return 0;
}
