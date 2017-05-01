/*************************************************************************
	> File Name: dehui5.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月01日 星期三 12时03分18秒
 ************************************************************************/
#include<cmath>
#include<iostream>
using namespace std;
int main(void)
{
    float a,b,c,ave,s;
    cin >> a >> b >> c;
    ave = (a+b+c)/2.0;
    if(a+b>c && a+c>b && b+c>a && abs(a-b)<c && abs(a-c)<b && abs(b-c) < a){
        cout << sqrt(ave*(ave-a)*(ave-b)*(ave-c)) << endl;   
    }else{
        cout << "No" << endl;
    }
}

