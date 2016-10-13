/*************************************************************************
	> File Name: wrong_return.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年09月28日 星期三 21时33分49秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<setjmp.h>

jmp_buf  env;

void handler_signalmin15(int signo)
{
    printf("recv SIGMIN+15\n");
    longjmp(env, 1);
}

void handler_sigrtmax15(int signo)
{
    printf("recv SIGMAX-15\n");
    longjmp(env, 2);
}

int main(void)
{
    switch(setjmp(env)){
        case 0:
            break;
        case 1:
            printf("return from SIGMIN+15\n");
            break;
        case 2 :
            printf("return from SIGMAX-15\n");
            break;
        default:
            break;
    }
    signal(SIGRTMIN+15, handler_signalmin15);
    signal(SIGRTMAX-15, handler_sigrtmax15);

    while(1){
        ;
    }
    return 0;
}
