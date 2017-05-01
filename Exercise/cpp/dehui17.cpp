#include<iostream>
using namespace std;
template<typename T>
void Mysort(T a[], int len){
    T temp;
      for(int i = 0; i < len-1; i++){
           for(int j = 0; j < len - i-1; ++j){
                if (a[j] > a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
           }
      }
}
template<typename T>
void Swap(T &t1, T &t2){
        T temp = t1;
        t1 = t2;
        t2 = temp;
}
//你提交的代码将被嵌入到这里

int main()
{
    int m,n,a[20],i,j;
    float b[20];
    cin>>m;         
    for(i=0;i<m;i++)
        cin>>a[i];
    cin>>n;
    for(j=0;j<n;j++)
        cin>>b[j];
    Mysort(a,m); 
    Mysort(b,n);
    for(i=0;i<m;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    for(j=0;j<n;j++)
        cout<<b[j]<<' ';
    cout<<endl;   
    return 0;   
}
