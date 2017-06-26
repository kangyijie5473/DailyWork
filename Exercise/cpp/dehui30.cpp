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
    
    string name1("encapsulation"),name2("inheritance"),name3("polymorphism"),name4("message"),name5("class"),name6("object"),name7("constructor"),name8("destructor");
    string s1("封装性"),s2("继承性"),s3("多态性"),s4("消息"),s5("类"),s6("对象"),s7("构造函数"),s8("析构函数");
    map<string,string> a;
    a.insert(make_pair(name1,s1));
    a.insert(make_pair(name2,s2));
    a.insert(make_pair(name3,s3));
    a.insert(make_pair(name4,s4));
    a.insert(make_pair(name5,s5));
    a.insert(make_pair(name6,s6));
    a.insert(make_pair(name7,s7));
    a.insert(make_pair(name8,s8));
    string key;
    cin >>  key;
    auto i = a.find(key);
    if( i  == a.end())
        cout << "抱歉！没有找到" << key << endl;
    else 
        cout << key << ":" << i->second  << endl;
}
