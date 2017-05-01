/*
 * > File Name: dehui19.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月28日 星期五 08时44分56秒
 */

#include <iostream>
#include <set>
using namespace std;
int main(void)
{
    set<string> a;
    string n;
    while(1){
        getline(cin,n);
        if(n == "end") break;
        a.insert(n);
    }
    while(1){
        getline(cin,n);
        if(n == "end") break;
        a.insert(n);
    }
    for(const auto &i : a)
        cout << i << endl;

}
