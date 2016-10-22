#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addStaff(char *name,short age,float wages);
void catStaff();
int rmStaff(int id);

typedef struct _STAFF{
    unsigned int ID;
    unsigned short age;
    char name[10];
    float wages;
    struct _STAFF *next;
}staff;

staff *p_head = NULL;
staff *p_tail = NULL;

int main(){
    char *name;
    short age;
    float wages;
    int sid;
    while(1){
        int Order = -1;
        printf("**员工档案管理系统**\n");
        printf("  1, 新增员工信息\n");
        printf("  2, 删除员工信息\n");
        printf("  3,更改员工信息\n");
        printf("  4,查询员工信息\n");
        printf("  5,保存\n");
        printf("  6,退出\n");
        scanf("%d",&Order);
        switch(Order){
            case 1:
                printf("请输入员工姓名:");
                scanf("%s",name);
                printf("请输入员工年龄:");
                scanf("%hu",&age);
                printf("请输入员工工资:");
                scanf("%f",&wages);
                addStaff(name,age,wages);
                break;
            case 2:
                printf("请输入要删除的员工:");
                scanf("%d",&sid);
                rmStaff(sid);
                catStaff();
                break;
            case 4:
                catStaff();
                break;
            case 6:
                return 0;
                break;
            default:
                printf("请输入正确的指令!\n");
        }
        printf("\n\n");
    }
}

void addStaff(char *name,short age,float wages){
    staff *tmp = malloc(sizeof(staff));
    strcpy(tmp->name,name);
    tmp->age = age;
    tmp->wages = wages;
    if(p_head == NULL){
        p_head = tmp;
        tmp->ID = 1;
    }else{
        tmp->ID = p_tail->ID + 1;
        p_tail->next = tmp;    
    }
    p_tail = tmp;
    return ;
}

void catStaff(){
    staff *tmp = p_head;
    while(tmp!=NULL){
        printf("ID:%d 姓名:%s -- 年龄:%hu -- 工资: %f\n",tmp->ID,tmp->name,tmp->age,tmp->wages);
        tmp = tmp->next;
    }
    return ;
}

int rmStaff(int id){
    staff *tmp = p_head;
    staff *tmpa = NULL;
    while (tmp!=NULL){
        if(tmp->ID == id){
            if(tmp->next->next){
                tmp->next= tmp->next->next;    
            }
            free(tmp);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
