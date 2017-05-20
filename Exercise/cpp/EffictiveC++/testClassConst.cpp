/*
 * > File Name: testClassConst.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月20日 星期六 16时33分40秒
 */

#include <iostream>
using namespace std;
class Gameer{
private :
    static const int num =5;
    int a[num];
};
//const int Gameer:: num = 5;
int main(void)
{
    Gameer a;
}
