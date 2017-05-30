/*
 * > File Name: dehui23.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月10日 星期三 08时01分32秒
 */

#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 3;

class atype {
    int a[SIZE];
public:
   atype( ) {
       register int i;
       for(i=0; i<SIZE; i++) a[i] = i;
  }
  int &operator[](int i);
};
//你提交的代码将被嵌入到这里
int & atype:: operator[](int i)
{
    if(i < SIZE)
        return atype::a[i];
    else{
    cout << "\nIndex value of 3 is out-of-bounds.\n";
    exit(1);
        
    }
        
}
int main( )
{
   atype ob;
   cin >> ob[1];  
   ob[2] = ob[1];  // 下标运算符[]出现在赋值运算符的左边和右边 
   cout << ob[2];  
   ob[3] = 44; // 产生运行时错误，下标3超出了数组边界
   return 0;
}

