/*
 * > File Name: dehui24.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月10日 星期三 08时54分15秒
 */

#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    int real;
    int xu;
    int fuhao =1 ;
    while(1)
    {
        char temp[100];
        scanf("%s",temp);
        if(strlen(temp) == 1 && temp[0] == '0') break;
        char *p = &temp[0];
        char *q = p,*j;
        while(*p != '+') {
            if(*p == '-'){
                fuhao = -1;
                break;
            }
        p++;
        }
        *p = '\0';
        j = ++p;
        while(*p != 'i') p++;
        *p = '\0';
        real += atoi(q);
        xu += atoi(j)*fuhao;
        fuhao = 1;
    }
    if(xu < 0){
    xu = xu *(-1);    
    cout << real << "-" << xu << "i" << endl;
    }
    else
    cout << real << "+" << xu << "i" << endl;


}
