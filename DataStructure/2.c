/*************************************************************************
	> File Name: 2.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月05日 星期三 12时41分03秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int a,b,c;
    int temp;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if(a > c){
        temp = a;
        a = c;
        c = temp;
    }
    if(b > c){
        temp = b;
        b = c;
        c = temp;
    }
    printf("%d %d %d\n",a,b,c);
}
