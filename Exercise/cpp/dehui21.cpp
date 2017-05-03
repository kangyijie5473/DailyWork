/*
 * > File Name: dehui20.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月28日 星期五 09时13分52秒
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(void)
{
    vector<string> name = {"Australian","Holland","Cameroon","Croatia","Spain","Chile","Brazil","Mexico" };
    vector<string> score = {"Spain","Chile","Brazil","Mexico","Australian","Holland","Cameroon","Croatia"};
    map<string,string> a;
    auto j = name.begin();
    auto k = score.begin();
    for(;j != name.end()&&k != score.end(); j++,k++)
    a.insert(make_pair(*j,*k));
    string name2;
    getline(cin, name2);
    auto i = a.find(name2);
    if( i  == a.end())
        cout <<  name2 <<"'s team has no match today." << endl;
    else 
        cout << name2 <<" team's rival is "<<i->second << "."  << endl;
}
