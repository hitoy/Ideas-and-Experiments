#include <stdio.h>
/*
 * 题目：输入某年某月某日，判断这一天是这一年的第几天？
 */
int is_leap(int year);

int main(){
    int year,month,day;
    printf("请输入日期格式 年-月-日:");
    scanf("%d-%d-%d",&year,&month,&day);
    if(is_leap(year) == 0 && month == 2 && day == 28){
        printf("This year do not has February 28th!\n");
        return 1;
    }

    if(month <= 2){
        printf("This is the %d day of this year\n",(month-1)*31+day);
    }else{
        int fed;
        int sum;
        if(is_leap(year) == 1){fed = 28;}else{fed=27;}
        //1,3,5,7,8,10,12 
        sum=(month-2)*30+fed;
        if(month <= 4){
            sum = sum + 2;
        }else if(month <= 6){
            sum = sum + 3;
        }else if(month <= 9){
            sum = sum + 5;
        }else if(month <= 11){
            sum = sum + 6;
        }else{
            sum = sum + 7;
        }
        sum = sum + day;
        printf("This is the %d day of this year\n",sum);
    }
    return 0;
}

int is_leap(int year){
    if(year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}
