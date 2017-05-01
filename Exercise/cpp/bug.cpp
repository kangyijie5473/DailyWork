#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    string tt;
    string tmp;
    getchar();
    while(getline(cin,tmp)) {
        stringstream ss(tmp);
        bool flag=1;
        int cnt=0;
        int ans=0;
        while(ss>>tt) {
            int t=atoi(tt.c_str());
            cnt++;
            if(cnt==1 && t==100) {
                flag=0;
                break;
            }
            if(cnt<=n) {
                ans+=t;
            }
        }
        if(flag==0) {
            break;
        }
        if(cnt<n) {
            if(cnt!=0)
                cout<<(ans/cnt)<<endl;
        } else
            cout<<(ans/(n))<<endl;
    }
    return 0;
}
