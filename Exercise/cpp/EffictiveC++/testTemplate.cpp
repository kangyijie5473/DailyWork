/*
 * > File Name: testTemplate.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月20日 星期六 17时45分11秒
 */

#include <iostream>
using namespace std;
template<typename T>
inline void Swap(T &t1,T &t2)
{
    T temp = t1;
    t1 = t2;
    t2 = temp;
}
int main(void)
{
    int a = 2;
    double b = 3.2;
    Swap(a,b); //模板函数可以检查类型不统一的情况
    cout << a << b << endl;
}
