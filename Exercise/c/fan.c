/*
 * > File Name: fan.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月27日 星期四 19时02分53秒
 */

#include <stdio.h>
#include <string.h>
#define MAX 20
void del(char *a,char *b)
{
    int i,j,k;
    char *temp;
    for(i = 0; i < strlen(a); i++){
        if(a[i] == b[0]){
            temp = &a[i];
            for(j = 1; j < strlen(b); j++){
                if(*++temp != b[j]) break;
            }
        }
        if(j == strlen(b)){
            for(k = i,j = i+strlen(b); j < strlen(a); k++,j++){
                a[k] = a[j];
            }
            a[k] = '\0';
            return ;
        }
            
    }

}
int main(void)
{
    char a[MAX],b[MAX];
    scanf("%s",a);
    scanf("%s",b);
    del(a,b);
    printf("%s\n",a);
}
