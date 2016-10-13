/*************************************************************************
	> File Name: 1.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月10日 星期一 13时25分37秒
 ************************************************************************/

#include<stdio.h>

int array[1000][1000];
int temp;
int n,m,q,x,y;

void fun1(int x, int y)
{
    for(int i = 0; i <= m; i++){
        temp = array[x-1][i];
        array[x-1][i] = array[y-1][i];
        array[y-1][i] = temp;
    }
    return;
}


void fun2(int x, int y)
{
    for(int i = 0; i <= n; i++){
        temp = array[i][x-1];
        array[i][x-1] = array[i][y-1];
        array[i][y-1] = temp;
    }
    return;
}

void fun3(int x, int y)
{
    for(int i = 0; i <= n; i++){
        array[x-1][i] += y;
    }
    return;
}

void fun4(int x, int y)
{
    for(int i = 0; i <= m; i++){
        array[i][x-1] += y;
    }
    return;
}
int main(void)
{
    scanf("%d%d%d",&m,&n,&q);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&array[i][j]);
        }
    }
   
    for(int i = 1; i <= q; i++){
        scanf("%d%d%d",&i,&x,&y);
        switch(i%4){
            case 1:
                fun1(x,y);
                break;
            case 2:
                fun2(x,y);
                break;
            case 3:
                fun3(x,y);
                break;
            case 0:
                fun4(x,y);
                break;
        }
    }
    printf("**********\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    } 
}
