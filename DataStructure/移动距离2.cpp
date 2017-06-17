/*
 * > File Name: 移动距离2.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月17日 星期六 10时31分21秒
 *
 *X星球居民小区的楼房全是一样的，并且按矩阵样式排列。其楼房的编号为1,2,3...当排满一行时，从下一行相邻的楼往反方向排号。
 *
 *例如：当小区排号宽度为6时，开始情形如下：
 *
 *1   2   3   4   5   6
 *
 *12  11  10  9   8   7
 *
 *13  14  15  .....
 *
 *问题是：已知了两个楼号m和n，需要求出它们之间的最短移动距离（不能斜线方向移动）
 *
 *输入
 *输入为3个整数w m n，空格分开，都在1到10000范围内。
 *
 *w为排号宽度，m,n为待计算的楼号。
 *
 *输出
 *输出一个整数，表示m n 两楼间最短移动距离。
 */
 
#include <iostream>
using namespace std;
int main(void)
{
    int w,m,n;
    int x1,x2,y1,y2;
    cin >> w >> m >> n;
    x1 = m / (w + 1) + 1;
    x2 = n / (w + 1) + 1;
    if(x1%2 == 1)
        if(m%w == 0)
            y1 = w;
        else 
            y1 = m % w;
    else if(m%w ==0)
            y1  = 1;
        else 
            y1 = w - (m % w) + 1;

    if(x2%2 == 1)
        if(n%w == 0)
            y2 = w;
        else 
            y2 = n % w;
    else if(n%w ==0)
            y2  = 1;
        else 
            y2 = w - (n % w) + 1;
    cout << x1<< y1 << endl<<  x2 <<  y2 << endl;  
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
}
