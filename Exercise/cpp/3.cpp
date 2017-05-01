
#include <iostream>
#include <string>
using namespace std;

template<typename T> 
T Max(const T &t1,const T &t2){
if (t1 < t2) return t2;
else return t1;
}

void foo()
{
    
}

template <class T>
T Max(T a,T b)
{
	return (a > b)?a:b;
}
:w

 int main()
{
  int m,n;
  char c,d;
  string s1,s2;
  cin>>m>>n;
  cin>>c>>d;
  cin>>s1>>s2;
  cout<<Max(m,n)<<endl;
  cout<<Max(c,d)<<endl;
  cout<<Max(s1,s2)<<endl;
    
     return 0 ;
}
