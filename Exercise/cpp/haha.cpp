/*
 * > File Name: haha.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月12日 星期三 08时12分08秒
 */

#include <iostream>
using namespace std;

template <typename t>
int compare(const t &v1,const t &v2)
{
    if (less<t>()(v1,v2)) return -1;
    if (less<t>()(v2,v1)) return 0;
}
int main(void)
{
    int a1,a2;
    cin >> a1 >> a2;
    cout << compare(a1,a2);

}
