#include <stdio.h>
#include <stdlib.h>
/*
 * 题目：两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。已抽签决定比赛名单。有人向队员打听比赛的名单。a说他不和x比，c说他不和x,z比，请编程序找出三队赛手的名单。
 */
int main(){
    char i,j;
    for(i="a";i<"d";i++){
        for(j = "x";j<="z";j++){
            //if((i!="a" && j !="x") && (i!="c" && j !="x") && (i!="c" && j !="z"))
                printf("%c ==>%c\n",i,j);
        }    
    }
    return 0;
}
