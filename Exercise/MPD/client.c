/*************************************************************************
	> File Name: multPthreadDown.c
	> Author: 
	> Mail: 
	> Created Time: 2016年12月08日 星期四 15时37分20秒
 ************************************************************************/
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"multPthreadDown.h"
int fd;
struct sockaddr_in serverAddr;
int key;
int main(void)
{
    fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("fd %d\n",fd);
    assert(fd > 0);
    
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5473);
    key = inet_aton("127.0.0.1", &serverAddr.sin_addr);
    key = connect(fd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr_in ));
    perror("connect");
    assert(!key);
    printf("no error\n");

    Message send_buffer;
    Message read_buffer;
    memset(&send_buffer, 0, sizeof(Message));
    memset(&read_buffer, 0, sizeof(Message));

    while(1){
        printf("put your file which you want to down:\n");
        scanf("%s",send_buffer.string);
        printf("your file is %s\n",send_buffer.string);
        send_buffer.flag = NAME;
        if((key = write(fd, &send_buffer, sizeof(Message))) == -1){
            printf("write is error\n");
            memset(&send_buffer, 0, sizeof(Message));
            continue;
        }
        printf("sending\n");
        //if((key = read(fd, &read_buffer, sizeof(Message)) == -1));
        read(fd, &read_buffer, sizeof(Message));
        printf("reading\n");
        if(read_buffer.flag == START){
            printf("Ok\n");
            return 1;
        }
    }


    

    

}
