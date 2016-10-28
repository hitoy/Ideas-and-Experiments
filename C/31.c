#include <stdio.h>
/*
 *题目：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。
 Monday,Tuesday,Wednesday,Thurday,Friday,Saturday,Sunday
 */
int main(){
    char i,j;
    printf("Please Input Day:");
    scanf("%c",&i);
    getchar();//这里如果不加getchar(), 下一个scanf就会把换行符扫描进去
    //还有问题，如果用户输入数组过多，后面的scanf还是会获取到多输入的数据
    switch(i){
        case 'm':
            printf("monday\n");
            break;
        case 't':
            printf("Please Input The Latter:");
            scanf("%c",&j);
            if(j=='u')
                printf("Tuesday\n");
            else
                printf("Thurday\n");
            break;
        case 'w':
            printf("wednesday\n");
            break;
        case 'f':
            printf("friday\n");
            break;
        case 's':
            printf("Please Input The Latter:");
            scanf("%c",&j);
            if(j=='u')
                printf("sunday\n");
            else
                printf("saturady\n");
            break;
        default:
            printf("Error!\n");
    }

    return 0;
}
