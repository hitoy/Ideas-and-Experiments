#include <stdio.h>
/*
 * ��Ŀ��һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ��
 */
int main(){
    int num;
    printf("Pleas Input A Number:");
    scanf("%d",&num);
    
    if(num/10000 == num%10 && num%10000/1000 == num%100/10){
        printf("YES\n");
    }else{
        printf("No\n");
    }
    return 0;
}
