#include <stdio.h>
/*
 * 题目：编写input()和output()函数输入，输出5个学生的数据记录。
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
    printf("请输入5个学生的姓名，性别，年龄");
    input(stu);
    printf("5个学生的姓名，性别，年龄分别如下");
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
