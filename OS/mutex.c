/*
 * > File Name: mutex.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年04月17日 星期一 20时30分28秒
 */

#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

#define LOOP_TIME 1000
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
void crirtical_section(int thread_num, int i)
{
    printf("Thread %d:%d\n",thread_num, i);
}
void *thread_worker(void *p)
{
    int i;
    for (i = 0; i < LOOP_TIME; i++){
        pthread_mutex_lock(&mutex1);
        pthread_mutex_lock(&mutex2);
        crirtical_section(2, i);
        pthread_mutex_unlock(&mutex2);
        pthread_mutex_unlock(&mutex1);
    }
}


int main(void)
{
    int rtn,i;
    pthread_t pthread_id = 0;
    rtn = pthread_create(&pthread_id, NULL, thread_worker, NULL);
    if (rtn != 0){
        printf("error\n");
        return -1;
    }
    for (i = 0; i < LOOP_TIME; i++){
        pthread_mutex_lock(&mutex1);
        pthread_mutex_lock(&mutex2);
        crirtical_section(1,i);
        pthread_mutex_unlock(&mutex2);
        pthread_mutex_unlock(&mutex1);
    }
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    return 0;
}
