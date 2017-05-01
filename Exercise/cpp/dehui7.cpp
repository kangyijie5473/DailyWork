/*************************************************************************
	> File Name: dehui7.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月02日 星期四 21时50分51秒
 ************************************************************************/

#include<iostream>
using namespace std;
int abc(int a){
    if(a >= 0){
        return a;
    }else 
        return a*(-1);
}
long abc(long a){
    if(a >= 0){
        return a;
    }else 
        return a*(-1);
    
}
double abc(double a){
    if(a >= 0){
        return a;
    }else 
        return a*(-1);
    
}
int main(void)
{

int x1; long x2; double x3;
  cin>>x1>>x2>>x3;
    cout<<"x1="<<abc(x1)<<endl;
      cout<<"x2="<<abc(x2)<<endl;
        cout<<"x3="<<abc(x3)<<endl;
          return 0;
}
