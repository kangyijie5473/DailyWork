/*************************************************************************
	> File Name: dehui15.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年04月05日 星期三 08时09分50秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<set>
using namespace std;
int main(void)
{
    map<string, size_t> word_count;
    string word;
    string key("hello");
    set<string> exc = {"The","Linux","group"};
    while(cin >> word){
        if(word == "hello")
            break;
        if(exc.find(word) == exc.end()){
            ++word_count[word];
        }
    }
    for(const auto &w: word_count){
        cout << w.first << "occurs " << w.second << ((w.second > 1) ? "times" : "time")<< endl;
    }
    
}
