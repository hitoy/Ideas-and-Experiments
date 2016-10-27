#include <stdio.h>
#include <stdlib.h>
/*
   *
  ***
 *****
*******
 *****
  ***
   *
  打印这个图形
 */

int main(){
    int i,j,space,last;
    for(i = 0 ; i < 7 ; i ++){
        for(j = 0 ;j< 7;j++){
            space = abs((3-i));
            last = 6 - space;
            if(j >= space && j <= last )
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
