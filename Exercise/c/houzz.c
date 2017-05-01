/*
 * > File Name: houzz.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月12日 星期三 18时26分24秒
 */

#include <stdio.h>
#include <string.h>
#define END '\0'
#define N   5
    const int n = 2;
int main(void)
{
    char array[N+1];
    int count = 0,len = N,flag = 0;
    //scanf("%d",&n);
    
    for(int i = 0; i < N; i++){
        array[i] = i+1;
    }
    char *head,*p;
    head = p = &array[0];
    p--;
    array[N] = END; 
    while(len != 1){
        p++;
        count++;
        printf("%d\n",*p);
        if(count == n){
            printf("*%d",*p);
            count = 0, len--;
            if(p == head) {
                head++;
                continue;
            }
            if(*(p+1) == END){
                *p = END;
                p = head;
                continue;
            }
            *p = END;
            strcat(head,++p);
            continue;
        }
        if(*(p+1) == END){
            p = head;
            continue;
        } 
    }
    printf("%d",*head);

}
