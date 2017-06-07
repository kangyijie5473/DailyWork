/*
 * > File Name: 贪心.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月04日 星期日 11时59分13秒
 *
 *
 * 问题：
 * 事件n 知道其开始时间，结束时间和收益
 * 在总结束时间无限制的情况下，最大收益是多少
 *
 */

#include <stdio.h>
struct item{
    int begin;
    int end;
    int value;
};
struct item it[100];
int max(int a,int b){
    if(a > b)
        return a;
    else return b;
}
int result(int n)
{
    int greedy[n];
    //按照结束时间排序 此处省略200个字
    //这一部很重要
    greedy[0] = it[0].value;           //第一次的值直接得到
    for(int i = 1; i < n; ++i){
        int j;
        for(j = i -1; j >=0;--j){      //向前遍历
            if(it[j].end < it[i].begin)//若兼容，即时间可以接上，直接跳出，此时受益大
                break;                 //不兼容，则再前看
        }
        if(j == -1)                    //若都不兼容，则此时受益为 单一天 或者之前最大的
            greedy[i] = max(it[i].value,it[i-1].value);
        else                           //若有兼容直接相加
            greedy[i] = it[j].value + it[i].value;
    }
    //整个收益数组为不递减数列，则最后一个最大
    return greedy[n-1];
}
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d",&it[i].begin,&it[i].end,&it[i].value);
    }
    printf("result : %d\n",result(n));

}
