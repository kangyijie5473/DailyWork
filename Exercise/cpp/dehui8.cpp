/*************************************************************************
	> File Name: cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年03月03日 星期五 08时59分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
int f(int a[], int c, int &max,int &min){
    max = a[0];
    for(int j = 0; j < c; j++){
        if(max < a[j])
        max = a[j]; 
    }
    min = a[0];
    for(int j = 0; j < c; j++){
        if(min > a[j])
        min = a[j]; 
    }
}
int main( )
{
  int a[10];
  int max,min,i;
  for(i=0;i<10;i++){
     cin>>a[i];
  }
  f(a,10,max,min);
  cout<<"Max: "<<max<<endl;
  cout<<"Min: "<<min<<endl;
  return 0;
}
