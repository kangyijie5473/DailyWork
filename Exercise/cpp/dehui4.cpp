/*************************************************************************
	> File Name: dehui4.cpp
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2017年02月28日 星期二 21时45分03秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
    vector<int> zero;
    vector<int> line;
    vector<int> aver;
int main(void)
{
    int K ,count, i = 0,t;
    int sum = 0, num =0;
    string str,temp,temp2;
    cin >> K ;
    cin.clear();
    while(getline(cin, str)){          // getline 为什么把上一个k也读了？
        if(str == "")                  //
            continue;                  // 处理上面的蛋疼
        if(str == "100"){
            break;
        }
        auto it = str.begin();
        while(it !=(str.end() + 1)){
            //cout << "*it" << *it << endl;
            if(*it == ' ' || it == (str.end() )){
                /*if(*(it+1) == ' '){
                    it++;
                    cout << "not" << endl;
                    continue;
                }*/
                line.push_back(atoi(temp.c_str()));
                for(int j = 0; j < i; j++){
                    temp[j] = 0;
                }
                //cout << i << "i"<< endl;
                i = 0;
            }else{
                temp[i] = *it;
                i++;
            }
            it++;
        }
        if((count = line.size()) > K){
            for(int num = 0; num < K; num++){
                sum += line[num];
                
            }
            num = 0;
            //aver.push_back(sum/K);
            cout << sum/K << endl; 
            t = sum/K;
            sum = 0;
        }else{
            for(auto i: line){
                sum += i;
            }
            //aver.push_back(sum/count);
            cout << sum/count  << endl;
            sum = 0;
        }
        line = zero;
    }
/*
    for(auto i: aver){
        cout << i << endl;
    }*/
}
