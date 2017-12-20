/*
 * C++实现括号匹配
 * 
 * OS：Linux(Fedora 25) 64bit 
 * Complier：g++ 6.4.1
 * C++ Standard：C++98/03
 * 
 */

#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;
FILE *fp = NULL; //测试文件的文件指针

/* 核心函数用于检查是否符合条件 */
int check()
{
	int lNum = 0;
	char buffer[1024];

	int r = fscanf(fp,"%s",buffer);       //读取字符串
	if (r == EOF){                        //读取失败，文件结束
	 	return -1;
	}	 
	int buffer_len = strlen(buffer);      //记录字符串长度
	for(int i = 0; i < buffer_len; i++){
		if(buffer[i] == '('){             //判断是否为 左括号
			lNum++;                       //左括号数增加
		}
		if(buffer[i] == ')'){
			lNum--;                       //若为右括号则左括号数减少，相当于一对匹配
			if(lNum < 0 ){                //如果做括号数小于0，说明没有正确匹配
				printf("NOK\n");          //正常结束，输出判定结果NOK
				return 0;
			}
		}
	}
	if(lNum != 0){                        //一行扫描结束，lNum不为0 有括号未匹配
		printf("NOK\n");                  //正常结束，输出判定结果NOK
		return 0 ;
	}
	printf("OK\n");                       //扫描结束，全部匹配。
	return 0;                             //正常结束，输出判定结果OK
}

/* 主函数 */
int main(void)
{
	fp = fopen("test.txt","r");          //打开被测试文件
	freopen("testresult.txt","w",stdout);//输出重定向，用于测试程序输出结果是否正确
	assert(fp);                          //测试打开文件是否成功

    /* 主循环 一旦读到文件末尾跳出循环程序结束*/
	while(1)
		if(check()==-1)
			break;
	return 0;
}
