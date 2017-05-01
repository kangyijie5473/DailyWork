/*************************************************************************
	> File Name: kxel.h
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月14日 星期二 16时43分42秒
 ************************************************************************/

#ifndef _KXEL_H
#define _KXEL_H
#include<iostream>
#include<string.h>
using namespace std;
const int MAXLEN = 512;
char local_file[MAXLEN];
bool init_kxel(char addr[], char file[], int port);
bool spilt_URL(char url[], char host_addr[], char host_file[], int *port_number);

class Kxel{
public:
    Kxel() = default; // 默认构造函数
    Kxel(string &addr, int port, string &file): port_number(port), host_addr(addr), host_file(file) {}
    Kxel(string &addr, string &file ):          port_number(80), host_addr(addr), host_file(file) {} 
    Kxel(int thread_num ,string &addr, string &file ):   
        range_byte(thread_num), port_number(80), host_addr(addr), host_file(file) {} 
    Kxel(int thread_num, int port, string &addr, string &file ):          
        range_byte(thread_num), port_number(port), host_addr(addr), host_file(file) {} 

    int    range_byte = 3;
    string host_addr;
    string host_file;
    int    port_number;

    bool set_http_message(void);
private:
    const string language = "zh-cn";
    const string user_agent = "Kxel";
    bool do_set_http_message(void);
};
#endif
