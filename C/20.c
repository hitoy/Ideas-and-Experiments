#include <stdio.h>
/*
 *题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
 */
int main(){
    float h,s;
    int i; 
    h = 100;
    s = 0;
    for(i = 1 ;i <= 11;i++){
        s += 2*h;
        printf("%d: Through path %f, height %f\n",i,s-100,h); 
        h = h/2;
    }
}
