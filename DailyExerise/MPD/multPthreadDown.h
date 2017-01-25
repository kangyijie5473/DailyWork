/*************************************************************************
	> File Name: multPthreadDown.h
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年01月18日 星期三 17时34分02秒
 ************************************************************************/

#ifndef _MULTPTHREADDOWN_H
#define _MULTPTHREADDOWN_H
#define MAXSIZE 1024
#define START 100
#define FINISH 101
#define NAME 102
#define ING  103
#define WRONG 104
typedef struct{
    unsigned int flag;
    unsigned int size;
    char pthread_number;
    char string[MAXSIZE];
}Message;
#endif

