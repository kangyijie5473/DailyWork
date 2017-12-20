/*
 * @filename:    demo.c
 * @author:      Jack Kang
 * @date:        2017年12月16日 09:46:40
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <string>
#include <queue>
#include <iostream>
FILE *fp = NULL;
void check()
{
    std::queue<std::string> st;

    int dataNum = 0;   //记录嵌套层数
    int t;
    char buffer[1024]; // 单行最长支持1024字符

    fscanf(fp, "%s",buffer);               //读取字符
    int length = strlen(buffer);           

    /*主循环*/

    for(int i = 0; i < length; i++){
        if(buffer[i] == '('){
            dataNum++;//嵌套层数增加
            t = i+1;

            while(buffer[t] != '(' && buffer[t] != ')')
                t++;

            /*数据段*/
            char tempBuffer[1024]={0};
            memcpy(tempBuffer, &buffer[i+1], t-i-1);

            /*标签头*/
            char tempHead[20];
            sprintf(tempHead, "<data_%d>",dataNum);
            std::string data = tempHead;

            /*加入队列*/
            st.push(data);
            st.push(std::string(tempBuffer));
            i = t-1;
            continue;
        }
        if(buffer[i] == ')'){

            /*标签尾*/
            char tempHead[20] = {0};
            sprintf(tempHead, "<\\data_%d>",dataNum);
            std::string data = tempHead;

            st.push(data);
            dataNum--;
        }
    }

    /*输出结果*/
    while(st.size() != 0){
        std::string out = st.front();
        std::cout << out ;
        st.pop();
    }
    std::cout <<"\"";
    std::cout << std::endl;
    
}
int main(void)
{
    freopen("result.csv","w",stdout); //输出重定向 
    std::cout << "nbr,source,result,err_pos,err_abbr,data_structure" << std::endl;
    fp = fopen("test.txt","r");       //输入文件

    /*打开文件异常处理*/
    if(fp == NULL){      
        std::cout << "open file error" << std::endl;
    }
    
    /*主函数*/
    check();
}
