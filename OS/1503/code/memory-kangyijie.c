/*
 * > File Name: memory.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月08日 星期一 11时06分25秒
 */

#include <stdio.h>
#include <stdlib.h>

#define PROC_NAME_LEN 32
#define MIN_SLICE  10 
#define DEFAULT_MEM_SIZE 1024
#define DEFAULT_MEM_START 0
#define MA_FF 1
#define MA_BF 2
#define MA_WF 3
int mem_size = DEFAULT_MEM_SIZE;
int ma_algorithm = MA_FF;
static int pid = 0;
int flag = 0;
/*内存空闲分区*/
typedef struct Free_block_type
{
    int size;
    int start_addr;
    struct Free_block_type *next;
}free_block_type;

/*已分配的内存块*/
typedef struct Allocated_block{
    int pid;
    int size;
    int start_addr;
    char process_name[PROC_NAME_LEN];
    struct Allocated_block *next;
}allocated_block;
void set_algorithm();
void do_exit();
void kill_process();
void display_menu();
int set_mem_size(); 
int free_mem(allocated_block *ab);
int  allocate_mem(allocated_block *);
free_block_type* init_free_block(int);
int dispose(allocated_block *);
allocated_block* find_process(int);

free_block_type *free_block;
allocated_block *alloc_phead = NULL;
free_block_type* init_free_block(int mem_size)
{
    free_block_type *fb;
    fb = (free_block_type *)malloc(sizeof(free_block_type));
    if(fb == NULL){
        printf("No memory\n");
        return NULL;
    }
    fb->size = mem_size;
    fb->start_addr = DEFAULT_MEM_START;
    fb->next = NULL;
    return fb;

}
int set_mem_size()
{
    int size;
    if(flag != 0){
        printf("cannot set memory size again");
        return 0;
    }
    printf("total memory size =");
    scanf("%d",&size);
    if(size > 0){
        mem_size = size;
        free_block->size = mem_size;
    }
    flag = 1;
    return 1;
}
int new_process()
{
    allocated_block *ab;
    int size;
    int ret;
    ab = (allocated_block *)malloc(sizeof(allocated_block));
    if(!ab)
        exit(-5); // 分配失败
    ab->next = NULL;
    pid++;
    sprintf(ab->process_name, "process-%02d", pid);
    ab->pid = pid;
    printf("memory for %s:", ab->process_name);
    scanf("%d",&size);
    if(size > 0)
        ab->size = size;
    ret = allocate_mem(ab);//分配给进程内存
    if(ret == 1 && alloc_phead == NULL){
        alloc_phead = ab;
        return 1;
    }else if(ret == 1){
        ab->next = alloc_phead;
        alloc_phead = ab;
        return 2;
    }else if(ret == -1){
        printf("allocation fail\n");
        free(ab);
        return -1;
    }
    return 3;
}

void rearrange_FF()
{

}
void rearrange_BF()
{

}
void rearrange_WF()
{

}
void rearrange(int algorithm)
{
    switch(algorithm){
    case MA_FF:
        rearrange_FF();
        break;
    case MA_BF:
        rearrange_BF();
        break;
    case MA_WF:
        rearrange_WF();
        break;
    }
}
int  display_mem_usage()
{
    free_block_type *fbt =  free_block;
    allocated_block *ab = alloc_phead;
    if(fbt == NULL)
        return -1;
    printf("------------------------------------------------------------------\n");
    printf("\n Free memory:\n");
    printf("%20s %20s \n","   start_addr","     size");
    while(fbt != NULL){
        printf("%20d %20d\n",fbt->start_addr, fbt->size);
        fbt = fbt->next;
    }
    printf("\n Used memory:\n");
    printf("%10s %20s %10s %10s\n","pid","process_name","start_addr","size");
    while(ab != NULL){
        printf("%10d %20s %10d %10d\n ",ab->pid,ab->process_name,ab->start_addr,ab->size);
        ab = ab->next;
    }
    printf("-----------------------------------------------------------------------\n");
    return 0;
}
void set_algorithm()
{
    int algorithm;
    printf("\t1- First fit\n");
    printf("\t2- Best fit\n");
    printf("\t1- Worst fit\n");
    scanf("%d",&algorithm);
    if(algorithm >=1 && algorithm <= 3)
        ma_algorithm = algorithm;
    rearrange(ma_algorithm);
}

int allocate_mem(allocated_block *ab)
{
    free_block_type *fbt, *pre;
    int requset_size = ab->size;
    fbt = pre = free_block;
    fbt = pre->next;
    while(fbt){
        /*找到 并且剩余大*/
        if(fbt->size >= requset_size && fbt->size - requset_size > MIN_SLICE){
            fbt->size -= requset_size;
            fbt->start_addr += requset_size;
            ab->start_addr = fbt->start_addr;
            rearrange(ma_algorithm);
            return 1;
        /*找到 剩余小，直接分配整个*/
        }else if(fbt->size >= requset_size && fbt->size - requset_size < MIN_SLICE){
            pre->next = fbt->next;
            ab->start_addr = fbt->start_addr;
            ab->size  = fbt->size;
            rearrange(ma_algorithm);
            return 1;
        }else {
            fbt = fbt->next;
            pre = pre->next;
        }
    }
    fbt = free_block->next->next;
    pre = free_block->next;

    /*利用内存紧缩再次查找*/
    while(fbt){
        if(fbt->size + pre->size == requset_size){

        }
        if(fbt->size + pre->size > requset_size){
            pre->size = fbt->size + pre->size - requset_size;
            fbt->size = 0;
            rearrange(ma_algorithm);
            return 1;
        }else{
            fbt = fbt->next;
            pre = pre->next;
        }
    }
    /*分配给进程内存失败     */  
    return -1;
}
void kill_process()
{
    allocated_block *ab;
    int pid ;
    printf("kill_process pid is \n");
    scanf("%d",&pid);
    ab = find_process(pid);
    if(ab != NULL){
        free_mem(ab);
        dispose(ab);
    }
}
int free_mem(allocated_block *ab)
{
    int algorithm = ma_algorithm;
    free_block_type *fbt, *pre, *work;
    fbt = (free_block_type *)malloc(sizeof(free_block_type));
    if(!fbt)
        return -1;
    /*
     *
     *
     *
     */
    return 1;
}
int dispose(allocated_block *free_ab)
{
    allocated_block *pre,*ab;
    if(free_ab == alloc_phead){
        alloc_phead = alloc_phead->next;
        free(free_ab);
        return 1;
    }
    pre = alloc_phead;
    ab = alloc_phead->next;
    while(ab != free_ab){
        pre = ab;
        ab = ab->next;
    }
    pre->next = ab->next;
    free(ab);
    return 2;
}
int main(void)
{
    char choice;
    pid = 0;
    free_block = init_free_block(mem_size);
    while(1){
        display_menu();
        fflush(stdin);
        choice = getchar();
        switch(choice){
        case '1': 
            set_mem_size(); // once
            break;
        case '2':
            set_algorithm();
            flag = 1;
            break;
        case '3':
            new_process();
            flag = 1;
            break;
        case '4':
            kill_process();
            flag = 1;
            break;
        case '5':
            display_mem_usage();
            flag = 1;
            break ;
        case '0':
            do_exit();
            exit(0);
        }
    }

}
