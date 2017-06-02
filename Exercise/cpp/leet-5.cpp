/*
 * > File Name: leet-5.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月02日 星期五 17时33分16秒
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
    public:
    string longestPalindrome(string s){
        if(s.size() == 1)
            return s;
        vector<string> sub_strs;
        string::iterator pre,next,end;
        end = s.end();
        string::iterator temp = s.begin();
        bool flag = false;
        temp++;
        for(pre = temp - 1,next = temp + 1; temp <= end - 2 ;++temp){
            while(1){
                if(*pre != *next){
                    if(flag){
                        sub_strs.push_back(string(pre+1,next));
                        flag = false;
                    }
                    break;
                }else{
                    flag = true;
                    --pre;
                    ++next;
                }
            }
            pre = temp;
            next = temp + 2;
        }
        temp = s.begin();
        flag  = false;
        for(pre = temp, next = temp +1;temp <= end -2; temp++){
            while(1){
                if(*pre != *next){
                    if(flag){
                        sub_strs.push_back(string(pre+1,next));
                        flag = false;
                    }
                    break;
                }else{
                    flag = true;
                    --pre;
                    ++next;
                }
            }
            pre = temp+1;
            next = temp+2;
        }
        if(sub_strs.size() == 0)
            return string("");
        int tt = 0;
        auto t = sub_strs.begin();
        auto i = sub_strs.begin();
        for(; i != sub_strs.end(); i++){
            if(i->size() >= tt)
                 t = i,tt = i->size();
        }
        
        return *t;
    }
};
int main(void)
{
    string s("bb");
    Solution a;
    cout << a.longestPalindrome(s) << endl;
}
