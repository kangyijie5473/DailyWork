/*************************************************************************
	> File Name: 10.3.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月22日 星期三 21时22分21秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main(void)
{
    vector<int> a{10,20,30,40};
    auto head = a.begin();
    auto end  = a.end();
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << sum << endl;
}

