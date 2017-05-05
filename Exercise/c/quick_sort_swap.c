/*************************************************************************
	> File Name: quick.c
	> Author: Jack Kang
	> Mail: xiyoulinux.kangyijie@gmail.com
	> Created Time: Fri May  5 11:42:45 2017
 ************************************************************************/

#include<stdio.h>

int s[8] = {22,5,1,2,7,3,12,56};
void quick_sort(int left,int right)
{
    if(left >= right)
        return;
    int p = left;
    int q = right;
    int temp = s[left];
    int  t;
    while(p != q){
        while(s[q] >= temp && q > p){
            q--;
        }
        while(s[p] <= temp && q > p){
            p++;
        }
        if(p < q){
            t = s[p];
            s[p] = s[q];
            s[q] = t;
        }
    }
    s[left] = s[p];
    s[p] = temp;
    quick_sort(left,p-1);
    quick_sort(p+1,right);

}
int main(void)
{
    quick_sort(0,7);
    for(int i = 0; i < 8; i++)
        printf("%d\n",s[i]);

}
