/*************************************************************************
	> File Name: dehui12.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月29日 星期三 08时28分37秒
 ************************************************************************/

# include<iostream>
using namespace std;
int main(void)
{
    string a,b;
    while(cin >> a >> b){
        auto a_begin = a.begin();
        auto b_begin = b.begin();
        if(*a_begin != *b_begin){
            cout << "No common prefix" << endl;
            continue;
        }
        while(*a_begin == *b_begin){
            a_begin++;
            b_begin++;
        }
        auto a_end = a.end();
        a.erase(a_begin,a_end);
        cout << "The common prefix is " << a << endl;
    }

}
