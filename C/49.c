#include <stdio.h>
/*
 * 题目：#if #ifdef和#ifndef的综合应用。
 */
#define MAX
#define MAXIMUM(x,y) (x>y)?x:y
#define MINIMUM(x,y) (x>y)?y:x

int main(){
    int a=10,b=20;
#ifdef MAX
    printf("the max number is %d\n",MAXIMUM(a,b));
#else
    printf("the min number is %d\n",MINIMUM(a,b));
#endif

#ifdef MIN
    printf("the min number is %d\n",MINIMUM(a,b));
#else
    printf("the max number is %d\n",MAXIMUM(a,b));
#endif

#undef MAX
#ifdef MAX
    printf("the max number is %d\n",MAXIMUM(a,b));
#else
    printf("the min number is %d\n",MINIMUM(a,b));
#endif

#define MIN
#ifdef MIN
    printf("the min number is %d\n",MINIMUM(a,b));
#else
    printf("the max number is %d\n",MAXIMUM(a,b));
#endif

    return 0;







}
