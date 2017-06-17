/*
 * > File Name: 牛顿插值法.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月12日 星期一 13时57分10秒
 */

#include <stdio.h>
int main(void)
{
    double x[10] = {0.017037,0.146447,0.370590,0.629410,0.853553,0.982963};
    double y[10] = {1.017183,1.157713,1.448590,1.876502,2.347975,2.672363};
    double c1[10],c2[10],c3[10],c4[10],c5[10];
    int n ;
    scanf("%d",&n);
    /*for(int i= 0;i < n; i++){
        scanf("%lf",&x[i]);
    }
    for(int i= 0;i < n; i++){
        scanf("%lf",&y[i]);
    }
    */
    for(int i = 0; i < n -1; i++){
        c1[i] = (y[i+1] - y[i])/(x[i+1] - x[i]);
        printf("c1[%d] = %.6lf",i,c1[i]);
    }
    printf("\n");
    for(int i = 0; i < n -2; i++){
        c2[i] = (c1[i+1] - c1[i])/(x[i+2] - x[i]);
        printf("c2[%d] = %.6lf ",i+1,c2[i]);
    }
    printf("\n");
    for(int i = 0; i < n -3; i++){
        c3[i] = (c2[i+1] - c2[i])/(x[i+3] - x[i]);
        printf("c3[%d] = %.6lf ",i+1,c3[i]);
    }
    printf("\n");
    for(int i = 0; i < n -4; i++){
        c4[i] = (c3[i+1] - c3[i])/(x[i+4] - x[i]);
        printf("c4[%d] = %.6lf ",i+1,c4[i]);
    }
    printf("\n");
    for(int i = 0; i < n -5; i++){
        c5[i] = (c4[i+1] - c4[i])/(x[i+5] - x[i]);
        printf("c5[%d] = %.6lf ",i+1,c5[i]);
    }
    double res[10];
    double xt[10] = {0.155026,0.293016,0.431005,0.568995,0.706984,0.844974};
    //res = c1[0]+c2[0]*(xt[i] - x[0])
    printf("\n");
    for(int i = 0; i < n ;i++){
        res[i] = y[0] +c2[0]*(xt[i] - x[0])*(xt[i] - x[1])+c3[0]*(xt[i]-x[0])*(xt[i] - x[1])*(xt[i] - x[2])+c4[0]*(xt[i] - x[0])*(xt[i] - x[1])*(xt[i] - x[2])*(xt[i] - x[3]) + c1[0]*(xt[i] - x[0]);
        printf("%.6lf\n",res[i]);
    }
    printf("\n");

}
