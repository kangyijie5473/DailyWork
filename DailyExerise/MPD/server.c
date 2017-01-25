/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2016年12月08日 星期四 16时34分36秒
 ************************************************************************/

#include<stdio.h>
#include"cJSON.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include"multPthreadDown.h"
#define LEN 256
void download(int connect_fd);
void *start1(void *fp);
int socket_fd, connect_fd;
int key;

int main(void)
{
    pthread_t pthid;
    struct sockaddr_in serverAddr;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    assert(socket > 0);
    int optrval = 1;
    key = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, (void *)&optrval, sizeof(int));
    assert(!key);
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5473);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    key = bind(socket_fd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr_in));
    assert(!key);
    key = listen(socket_fd, LEN);
    assert(!key);
    int clientLen = sizeof(serverAddr);
    /*
    while(1){
        if(connect_fd = accept(socket_fd, (struct sockaddr *)&serverAddr, &clientLen) > 0){
            pthread_create(&pthid, NULL, (void *)download, (void *)connect_fd);
        }else{
            continue;
        }
    }
}
void *download(int connect_fd)
{
    printf("welcome %d\n",connect_fd);
}
    */
    pid_t pid;
    while(1){
        if(connect_fd = accept(socket_fd, (struct sockaddr *)&serverAddr, &clientLen) > 0){
            printf("conn %d\n",connect_fd);
            pid = fork();
            assert(pid != -1);
            if(pid == 0){
                download(connect_fd);
            }else {
                continue;
            }
        }
    }
}
void download(int connect_fd)
{
    printf("%d is connect\n",connect_fd);
    Message recv_buffer;
    Message send_buffer;
    FILE *fp;
    while(1){
        memset(&recv_buffer, 0, sizeof(Message));
        read(connect_fd, &recv_buffer, sizeof(Message));
        printf("test ->  %s\n",recv_buffer.string);
        if(recv_buffer.flag == NAME && strlen(recv_buffer.string) != 0){
            if((fp = fopen(recv_buffer.string, "r")) != NULL){
                printf("want to down %s\n",recv_buffer.string);
                break;
            }else{
                memset(&send_buffer, 0, sizeof(Message));
                send_buffer.flag = WRONG;
                write(connect_fd, &send_buffer, sizeof(Message));
            }
        }
    }
    memset(&send_buffer, 0, sizeof(Message));
    send_buffer.flag = START;
    write(connect_fd, &send_buffer, sizeof(Message));

    //pthread_t p1;
    //p1 = pthread_create(&p1, NULL, (void *)start1, fp);
}
void *start1(void *fp)
{
    
}

