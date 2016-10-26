#include <stdio.h>
/*
 * 有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
 */
int main(){
    int i,k,j;
    for(i = 0 ; i < 4; i++){
        int b = i +1;
        for(k = 0 ; k < 4; k++){
            int s = k + 1;
            if(s == b) continue;
            for(j = 0 ; j < 4; j ++){
                int g = j + 1;
                if(g == s || g== b) continue;
                printf("%d,%d,%d\n",b,s,g);
            }
        }
    }
}
