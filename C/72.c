#include <stdio.h>
#include <stdlib.h>
/*
 * ��Ŀ������һ������
 */

typedef struct ST_Student{
    char name[20];
    char sex[5];
    int age;
    struct ST_Student *next;
}STU;

STU Head = NULL;
int main(){



}

STU create_stu()
{
    STU *p = malloc(sizeof(STU));
    printf("�������������Ա�����:");
    scanf("%s,%s,%d"&(p->name),&(p->sex),&(p->age));
    if(Head ==NULL){
        Head=p;
    }
    p->next=NULL;
    return *p;
}
