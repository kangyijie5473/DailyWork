/*
 * > File Name: dehui20.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月28日 星期五 09时13分52秒
 */

#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    string name;
    int score;
    map<string,int> a;
    while(1){
        cin >> name ;
        if(name == "noname") break;
        cin >> score;
        a.insert(make_pair(name,score));
    }
    string name2;
    getchar();
    getline(cin, name2);
    cout << name2 << endl;
    auto i = a.find(name2);
    if( i  == a.end())
        printf("Not Found.\n");
    else 
        cout << i->second * 0.21 << endl;
}
