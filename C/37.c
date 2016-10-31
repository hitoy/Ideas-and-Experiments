#include <stdio.h>
/*
 * 题目：对10个数进行排序。
 */
int main(){
    int num[10];
    int i = 0,j;
    while(i < 10){
        printf("Please Input the %d number:",i+1);
        scanf("%d",&num[i]);
        i++;
    }
    //冒泡排序
    int tmp;
    for(i = 9;i>=0;i--){
        for(j = 0;j<i;j++){
            if(num[j] > num[j+1]){
                tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }   
    }
    for(i = 0 ; i < 10;i++){
        printf("%d,",num[i]);
    }
}
