/*
 * > File Name: thread.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月16日 星期日 17时58分14秒
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREAD 3
unsigned long long main_counter,counter[MAX_THREAD];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *thread_worker(void *p)
{
    int thead_num;
    thead_num = *(int *)p;
    for(;;){
        pthread_mutex_lock(&mutex1);
        counter[thead_num]++;
        main_counter++;
    }
    
}
int main(int argc, char **argv)
{
    int i,rtn = 0,ch;
    int key[3]= {0,1,2};
    pthread_t pthread_id[MAX_THREAD] = {0};
    for (int i= 0; i < MAX_THREAD; i++){
        pthread_create(&pthread_id[i], NULL, thread_worker, (void *)&key[rtn++]);
    }
    do{
        unsigned long long sum = 0;
        for(i = 0; i < MAX_THREAD; i++){
            sum += counter[i];
            printf("counter[%d]--->%llu\n",i,counter[i]);
        }
        printf("%llu--%llu\n",main_counter, sum);
        pthread_mutex_unlock(&mutex1);
    }while((ch = getchar()) != 'q');
    pthread_mutex_destroy(&mutex1);
}


