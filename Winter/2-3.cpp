/*************************************************************************
	> File Name: 2-3.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年01月11日 星期三 21时07分50秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(void)
{
    unsigned u =10,u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2= 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout <<  u - i << std::endl;
}
