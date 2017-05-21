/*************************************************************************
	> File Name: fan1.c
	> Author: Jack Kang
	> Mail: xiyoulinux.kangyijie@gmail.com
	> Created Time: 2017年05月21日 星期日 15时54分51秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define N 20
struct Candidate{
    char name[N];
    int count;
}; 
struct Candidate  candidate[3];
void print_result()
{
    int i;
    for(i = 0; i < 3; i++)
        printf("%s候选人得到%d票\n",candidate[i].name,candidate[i].count);

}
void get_lower(char *str)
{
    int len = strlen(str);
    int i;
    for(i = 0;i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
    }
}
int main(void)
{
   int i = 0;
   int wrong = 0;   //废票数
   char get_name[N];//输入的姓名
   /*初始化三个姓名*/
   strcpy(candidate[0].name,"zhang");
   strcpy(candidate[1].name,"li");
   strcpy(candidate[2].name,"wang");
   /* 选民输入姓名*/
    for(i = 0; i < 10; i++){
        scanf("%s",get_name); //录入
        get_lower(get_name);  //若为大写字母转换为小写
        /*判断是哪个人*/
        if(!strcmp(get_name,"zhang")){
            candidate[0].count++; //对应的人票数增加
            continue;             //退出本次循环开启下一次
        }else if(!strcmp(get_name,"li")){
            candidate[1].count++;
            continue;
        }else if(!strcmp(get_name,"wang")){
            candidate[2].count++;
            continue;
        }else {
            wrong++; //若3个都不符合，算废票
            continue;
        }
    } 
   print_result();   //打印结果
   printf("废票%d张\n",wrong);
}
