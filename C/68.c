#include <stdio.h>
#include <stdlib.h>
void move_array(int *arr,int n,int offset);
void print_array(int *arr,int n);
/*
 * ��Ŀ����n��������ʹ��ǰ�����˳�������m��λ�ã����m���������ǰ���m������
 */
int main(){
    int *p = malloc(sizeof(int));
    int num,i=0;
    while(num!=0){
        printf("������һ������(����0��������):"); 
        scanf("%d",&num);
        if(num == 0) break;
        p[i] = num;
        p = realloc(p,sizeof(int)*(i+2));
        i++; 
    }
    /*
    printf("����������ƫ����:");
    scanf("%d",num);
    move_array(p,i+1;num);
    */
    print_array(p,i);
    return 0;
}


void move_array(int *array,int n,int offset){
    if(offset>=n){
        printf("offset to large!\n");
        exit(0);
    }
    int i,last;
    for(i=n-1;i>offset;i--){
        last = array[n-1];
    
    
    }
}

void print_array(int *array,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%4d",array[i]);   
    }
    printf("\n");
}
