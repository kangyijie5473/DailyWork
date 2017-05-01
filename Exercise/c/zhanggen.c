/*
 * > File Name: zhanggen.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月14日 星期五 20时44分07秒
 */

#include <stdio.h>
#define NAME(n) x##n
#define PRINTVAL(y, ...) printf("x"#y":" __VA_ARGS__)
int main(int argc, char **argv)
{
    int NAME(1);
    short *NAME(2) = (short *)&NAME(1);
    char *NAME(3) = (char *)&NAME(1);
    NAME(1) = 0;
    *NAME(2) = -1;
    PRINTVAL(1,"%x\n",NAME(1));
    PRINTVAL(2,"%x\n",*NAME(2));
    PRINTVAL(3,"%x\n",*NAME(3));
}
