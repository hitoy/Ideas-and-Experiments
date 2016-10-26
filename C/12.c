#include <stdio.h>
#include "math.h"
/*
 * 判断101到200之间的素数。
 */
int main(){
    int i,j;
    for(i = 101;i<202;i++){
        if(is_su(i) == 1){
            printf("%d\n",i);
        }
    }
}

int is_su(int s){
    int i = 2;
    while(i<sqrt(s)){
        if(s%i==0) return 0; 
        i++;
    }
    return 1;
}
