/*************************************************************************
	> File Name: demo-debian.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月13日 星期四 19时25分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"kmp.c"
int main(void)
{
    int count = 0;
    FILE *fp;
    char buffer[300],objVersion[100];
    char *objProgram = "vim";
    char *tail,*head;
    int len;
    system("apt-show-versions | grep uptodate >> temp-debian");
    fp = fopen("temp-debian","r");
    while(feof(fp) == 0){
        fgets(buffer, 199, fp);
        if(mykmp(buffer, objProgram) != -1){
            len = strlen(buffer);
            tail = &buffer[len];
            while(*(--tail) != ' ') ;
            head = tail;
            *tail = '\0';
            while(*(--head) != ' '&& *(head) != ':') ;
            strcpy(objVersion,head+1);
            printf("%s\n",objVersion);
            system("rm temp-debian");
            break;
        }
        memset(buffer, 0, sizeof(buffer));
        
    }
    
}
