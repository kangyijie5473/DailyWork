/*************************************************************************
	> File Name: demo.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月12日 星期三 14时34分07秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"kmp.c"
int main(void)
{
    FILE *fp;
    char linuxVersion[100];
    char *objVersion = "deepin";
    int i;
    system("uname -r >> temp");
    fp = fopen("temp","a+");
    fgets(linuxVersion, 99,fp);
    printf("%d\n",i = mykmp(linuxVersion,objVersion));
    system("rm ./temp");
}
