#include <stdio.h>
/*
 * ��Ŀ����дinput()��output()�������룬���5��ѧ�������ݼ�¼��
 */

typedef struct{
    char name[20];
    char sex[5];
    short int age;
}Stu;
void input(Stu *stu);
void output(Stu *stu);

int main(){
    Stu stu[5];
    printf("������5��ѧ�����������Ա�����");
    input(stu);
    printf("5��ѧ�����������Ա�����ֱ�����");
    output(stu);
    return 0;
}
void input(Stu *stu){
    int i;
    for(i=0;i<1;i++){
        scanf("%s %s %d",&(stu[i].name),&(stu[i].sex),&(stu[i].age));
    }
}
void output(Stu *stu){
    int i = 0;
    for(i=0;i<1;i++){
        printf("%s %s %d",stu[i].name,stu[i].sex,stu[i].age);
    }
}
