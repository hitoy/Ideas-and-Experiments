#include <stdio.h>
/*
 * ��Ŀ����һ��������5λ����������Ҫ��һ�������Ǽ�λ�������������ӡ����λ���֡�
 */
int main(){
    int a,b,c,d,e,input;
    printf("Please Input Names:");
    scanf("%d",&input);
    a = input/10000;
    b = input%10000/1000;
    c = input%1000/100;
    d = input%100/10;
    e = input%10;
    if (a!=0){
        printf("Ϊ 5 λ��,����Ϊ�� %d %d %d %d %d\n",e,d,c,b,a);
    } else if(b!=0) {
         printf("Ϊ 4 λ��,����Ϊ�� %d %d %d %d\n",e,d,c,b);
    } else if(c!=0) {
         printf("Ϊ 3 λ��,����Ϊ��%d %d %d\n",e,d,c);
    } else if(d!=0) {
         printf("Ϊ 2 λ��,����Ϊ�� %d %d\n",e,d);
    } else if(e!=0) {
         printf("Ϊ 1 λ��,����Ϊ��%d\n",e);
    }
    return 0;
}
