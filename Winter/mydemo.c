/*************************************************************************
	> File Name: mydemo.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年02月22日 星期三 19时49分04秒
 ************************************************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <limits.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <assert.h>
#define FALSE 1
#define TRUE 0
#define MAXLEN 256
int spilt_URL(char url[], char host_addr[], char host_file[], int *port_number)
{
    char *p = NULL;
    if((p = strstr(url, "http://")) == NULL){
        if((p = strstr(url, "https://")) == NULL){
            puts("非http/https协议");
            return FALSE;
        }else p += 8;
    }
    p += 7;
    printf("%s\n",p);
    char *q;
    q = strchr(p,'/');
    strncpy(host_addr, p, q-p);
    p = &(url[strlen(url) - 1]);
    while( *p != '/'){
        p--;
    }
    memcpy(host_file,p+1,strlen(p+1));
    char *temp;
    temp = p = strstr(host_addr, ":");
    if(p){
        *port_number = atoi(p+1);
        *p = '\0';
    }else{
        *port_number = 80;
    }

    return TRUE;
}
int main(int argc, char *argv[])
{
    char host_addr[MAXLEN] = {0};
    char host_file[MAXLEN] = {0};
    char buffer[2] = {0};
    char request[2*MAXLEN] = {0};
    int port_number,request_len;
    int socketfd;
    int key , i = 0,totalsend = 0;
    FILE *fp;
    struct hostent *host;
    struct sockaddr_in server_addr;
    if(argc != 2){
        printf("参数错误 格式为 %s + URL\n",argv[0]);
        return 1;
    }
    key = spilt_URL(argv[1],host_addr,host_file,&port_number);
  printf("webhost:%s\n", host_addr);
  printf("hostfile:%s\n", host_file);
  printf("portnumber:%d\n\n", port_number);
    if(key == FALSE){
        puts("URL格式错误 无法识别");
        return 1;
    }
    if((host=gethostbyname(host_addr)) == NULL){
        fprintf(stderr, "gethost error : %s",strerror(errno));
        return 1;
    }
    if((socketfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
        fprintf(stderr, "socket error : %s",strerror(errno));
        return 1;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if(connect(socketfd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr)) == -1){
        fprintf(stderr, "connect error : %s",strerror(errno));
        return 1;
    }
    sprintf(request,"GET /%s HTTP/1.1\r\nAccept: */*\r\nAccept-Language: zh-cn\r\nUser-Agent: %s(Linux 4.8 x86_64)\r\nHost: %s:%d\r\nConnection: Close\r\n\r\n",host_file,argv[0],host_addr, port_number);
    request_len = strlen(request);
    while(totalsend < request_len){
        key = write(socketfd, request+totalsend,request_len-totalsend);
        if(key == -1){
            fprintf(stderr, "write error: %s\n",strerror(errno));
            return 1;
        }
        totalsend += key;
    }
    if((fp = fopen(host_file, "a")) == 0){
        fprintf(stderr , "fopen error : %s\n",strerror(errno));
        return 1;
    }
    while((key = read(socketfd, buffer, 1))==1){
        if(i < 4)  {
            if(buffer[0] == '\r' || buffer[0] == '\n')  
                i++;
            else i = 0;
        }  else{
            fwrite(buffer, 1, 1, fp);/*将http主体信息写入文件*/
            i++;
            if(i%1024 == 0) 
                fflush(fp);/*每1K时存盘一次*/
        }
    }
    fclose(fp);
    close(socketfd);
    return 0;
}
