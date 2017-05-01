/*************************************************************************
	> File Name: dehui11.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月22日 星期三 09时08分20秒
 ************************************************************************/

#include<iostream>
#include<cstring>

using namespace std;
int main()
{
    char *p;
    string a;
    getline(cin,a) ;
    p = &a[a.size() -1];
    while(*p != '/'&&*p != '\\'){
        p--;
    }
    *p = '\n';
    cout << a << endl;

}
