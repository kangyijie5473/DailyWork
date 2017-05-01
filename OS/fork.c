/*
 * > File Name: fork.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月11日 星期二 10时24分10秒
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    int count = 0;
    pid = fork();
    if(pid == 0){
        printf("I am child process, pid  = %d \n",getpid());
        count++;
    }else{
        printf("I am father process, pid = %d \n",getpid());
        count++;
    }
    return 0;

}
