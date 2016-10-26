#include <stdio.h>
/*
 * ³Ë·¨¿Ú¾÷
 */
int main(){
    int i,j;
    for(i = 1;i<10;i++){
        for(j = 1; j < 10;j++){
            if(j>i) break;
            printf("%d x %d = %d\t",i,j,i*j);
        }
        printf("\n");
    }
    return 0;
}
