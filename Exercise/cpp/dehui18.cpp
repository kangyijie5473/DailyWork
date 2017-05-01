/*
 * > File Name: dehui18.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月28日 星期五 08时18分04秒
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    int n;
    string temp;
    cin >> n;
    getchar();
    vector<string> a;
    while(n--){
        getline(cin,temp);
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    for(auto i = a.begin(); i != a.end(); i++)
        cout << *i << endl;

}
