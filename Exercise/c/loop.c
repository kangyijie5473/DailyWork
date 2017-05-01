/*
 * > File Name: loop.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月14日 星期五 14时55分58秒
 */

#include <stdio.h>
#define P_NUMBER  5
#define ALIVE 0
#define DIE   1

int main(void)
{
    int people[P_NUMBER] = {ALIVE};
    int len = P_NUMBER;
    int n,count = 0,i = 0;
    scanf("%d",&n);   // 每隔几个出列
    while(len != 1){  // 只剩一个就退出
        if(people[i] == DIE){ //如果是DIE 则查看下一个
            if(i == P_NUMBER -1) i = -1; //到数组结尾 将 i 置为 0
            i++;
            continue;
        }else {
            count++; // 如果不是DIE 计数
        }
        if(count == n) { // 满足则出列。人数-1，计数重置
            people[i] = DIE;
            count = 0;
            len--;
        }
        if(i == P_NUMBER -1){ // 到数组结尾 ，将 i 置为 0
            i = 0;
            continue;
        } 
        i++; // 一般情况 即当前是ALIVE 且 计数不满足 查看下一个
    }
    /*for循环找到还是ALIVE的人*/
    int key;
    for(int i = 0; i < P_NUMBER; i++){
        if(people[i] == ALIVE) {
         key = i; //key就是在数组里的序号
         break;
        }
    }
    //第key+1个
    printf("%d",key+1);
}
