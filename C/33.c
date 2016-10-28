#include <stdio.h>
#include <math.h>

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

    while(1){
        printf("Please Input A number:");
        scanf("%ld",&num);
        if(is_prime(num) == 1)
            printf("%d is A Prime Number\n",num);
        else
            printf("%d is not A Prime Number\n",num);
    }
    return 0;
}
