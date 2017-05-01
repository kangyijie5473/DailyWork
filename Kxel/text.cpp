/*************************************************************************
	> File Name: text.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月14日 星期二 16时43分25秒
 ************************************************************************/
#include "kxel.h"
bool spilt_URL(char url[], char host_addr[], char host_file[], int *port_number)
{
    char *p = NULL;
    if((p = strstr(url, "http://")) == NULL){
        if((p = strstr(url, "https://")) == NULL){
            puts("非http/https协议");
            return false;
        }else p += 8;
    }
    p += 7;
    printf("%s\n",p);
    char *q;
    q = strchr(p,'/');
    strncpy(host_addr, p, q-p);
   
    p = &(url[strlen(url) - 1]);        //
    while( *p != '/'){                  //
        p--;                            //
    }                                   //
    memcpy(local_file,p+1,strlen(p+1)); //  生成本地文件名
    
    memcpy(host_file,q+1,strlen(q+1));  //  
    //除了形如http://222.24.19.3:81/xiyoucs/index.asp 这样的端口
    char *temp;                        
    temp = p = strstr(host_addr, ":");
    if(p){
        *port_number = atoi(p+1);
        *p = '\0';
    }else{
        *port_number = 80;
    }

    return true;
}
void test()
{
}
int main(int argc, char **argv)
{

}
