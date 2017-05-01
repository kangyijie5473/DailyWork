/*************************************************************************
	> File Name: dehui13.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月29日 星期三 08时49分43秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char a[60];
    scanf("%s",a);
    if(strlen(a) !=  11) {
        puts("No");
        return 0;
    }
    if(a[0] != '1') {
        puts("No");
        return 0;  
    } 
    for(int i = 0; i < 11; i++){
        if(a[i] >= '0' && a[i] <= '9') continue;
        puts("No");
        return 1;
    }
    puts("Yes");
}
