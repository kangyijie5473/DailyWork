/*
 * > File Name: 分核桃.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月17日 星期六 09时56分58秒
 *题目描述
 *小张是软件项目经理，他带领3个开发组。工期紧，今天都在加班呢。为鼓舞士气，小张打算给每个组发一袋核桃（据传言能补脑）。他的要求是：
 *
 *（1）各组的核桃数量必须相同；
 *
 *（2）各组内必须能平分核桃（当然是不能打碎的）
 *
 *（3）尽量提供满足1,2条件的最小数量（节约闹革命嘛）
 *
 *输入
 *输入包含三个正整数a,b,c，表示每个组正在加班的人数，用空格分开 (a,b,c均小于30)。
 *
 *输出
 *输出一个正整数，表示每袋中核桃的数量，不要输出多余的信息。
 */

#include <iostream>
using namespace std;
int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;
    int i = 1;
    while(1){
        if(i%a == 0 && i%b == 0 && i%c == 0)
            break;
        else i++;
    }
    cout << i << endl;
}
