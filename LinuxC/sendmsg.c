/*************************************************************************
	> File Name: sendmsg.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月07日 星期五 19时18分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#define BUF_SIZE 256
#define PROJ_ID 32
#define PATH_NAME "."

int main(void)
{
    struct mymsgbuf{
        long msgtype;
        char ctrlstring[BUF_SIZE];
    }msgbuffer;

    int qid;
    int msglen;
    key_t msgkey;

    if((msgkey = ftok(PATH_NAME, PROJ_ID)) == -1){
        perror("ftok error");
        exit(1);
    }

    if((qid = msgget(msgkey, IPC_CREAT | 0660)) == -1){
        perror("msgget error");
        exit(1);
    }
    
    msgbuffer.msgtype = 3;
    strcpy(msgbuffer.ctrlstring, "hello message queue");
    msglen = sizeof(struct mymsgbuf) - 4;
    if(msgsnd(qid, &msgbuffer, msglen, 0) == -1){
        perror("msgget error");
        exit(1);
    }
    exit(0);
}
