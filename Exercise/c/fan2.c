/*
 * > File Name: fan2.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月21日 星期日 17时02分06秒
 */

#include<stdio.h>
#include<math.h>
FILE *fp_read;
FILE *fp_write;
struct Point{
    float x1;
    float y1;
    float x2;
    float y2;
    float distance;
};
struct Point points[10];
void get_distance(int i)
{
    float temp1 = (points[i].x1-points[i].x2)*(points[i].x1-points[i].x2);
    float temp2 = (points[i].y1-points[i].y2)*(points[i].y1-points[i].y2);
    points[i].distance = sqrt(temp1+temp2);
}
int main(void)
{   /*打开文件*/
    fp_read = fopen("1.txt","r");//读数据文件1.txt
    fp_write = fopen("2.txt","w");//结果写到2.txt
    int i;
    /*读到结构体中*/
    for(i = 0; i < 10; i++){
        fscanf(fp_read,"%f%f%f%f",&points[i].x1,&points[i].y1,&points[i].x2,&points[i].y2);
        get_distance(i); // 计算距离
    }
    /*写到文件里*/
    for(i = 0; i < 10; i++){
        fprintf(fp_write,"(%.2f,%.2f) (%.2f,%.2f):  %.3f\n",points[i].x1,points[i].y1,points[i].x2,points[i].y2,points[i].distance);
    }
    /*关闭文件*/
    fclose(fp_read);
    fclose(fp_write);
}
