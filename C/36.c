#include <stdio.h>
#include <math.h>

/*题目：求100之内的素数。*/

int is_prime(long int n){
    int i = 2;
    int sqr = sqrt(n)+1;
    while(i<sqr){
        if(n % i == 0){
            return 0;
        }
        i++;
    }
    return 1;
}

int main(){
    int num;
    printf("Please Input MAX number:");
    scanf("%d",&num);
    while(num>1){
        if(is_prime(num)){
            printf("%d ",num);
        }
        num--;
    }
    return 0;
}
