/*************************************************************************
	> File Name: recmsg.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月07日 星期五 19时39分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define BUF_SIZE 256
#define PROJ_ID 32
#define PATH_NAME "."

void getmsgattr(int msgid, struct msqid_ds msq_info);

int main(void)
{
    struct mymsgbuf{
        long msgtype;
        char ctrlstring;
    }msgbuffer;
    int qid;
    int msglen;
    key_t msgkey;
    struct msqid_ds msg_attr;

    if((msgkey = ftok(PATH_NAME, PROJ_ID)) == -1){
        perror("ftok error");
        exit(1);
    }

    if((qid = msgget(msgkey, IPC_CREAT | 0660)) == -1){
        perror("msgget error");
        exit(1);
    }


    msglen = sizeof(struct mymsgbuf) -4;
    if(msgrcv(qid, &msgbuffer, msglen, 3, 0) == -1 ){
        perror("msgrcv error");
        exit(1);
    }

    printf("Get message%s",msgbuffer.ctrlstring);
    exit(0);
}
