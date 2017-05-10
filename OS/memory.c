/*
 * > File Name: memory.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月08日 星期一 11时06分25秒
 */





/*
 * bug: 杀死进程后回收内存存在问题
 *
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
void sort_list_by_addr();
void merge_free_block();
void rearrange(int algorithm);

free_block_type *free_block;
allocated_block *alloc_phead = NULL;
free_block_type empty_head_node;
int mem_size = DEFAULT_MEM_SIZE;
int ma_algorithm = MA_FF;
static int pid = 0;
int flag = 0;

free_block_type* init_free_block(int mem_size)
{
    free_block_type *fb;
    fb = (free_block_type *)malloc(sizeof(free_block_type));
    if(fb == NULL){
        printf("No memory alloced from heap\n");
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
    flag = 1; // flag被设置 保证size只能被设置一次
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

void set_algorithm()
{
    int algorithm;
    printf("\t1- First fit\n");
    printf("\t2- Best fit\n");
    printf("\t3- Worst fit\n");
    scanf("%d",&algorithm);
    if(algorithm >=1 && algorithm <= 3)
        ma_algorithm = algorithm;
    rearrange(ma_algorithm);
}

void rearrange_FF()
{
    if(free_block->next == NULL||
       free_block == NULL)
        return;

    empty_head_node.next = free_block;
    free_block_type *p,*x,*y,*f = NULL;
    while(f != empty_head_node.next->next){
        for(p = &empty_head_node; p->next->next != f; p = p->next){
            if(p->next->start_addr > p->next->next->start_addr){
                x = p->next;
                y = p->next->next;
                p->next = y;
                x->next = y->next;
                y->next = x;
            }
        }
        f = p->next;
    }

    

}
void rearrange_BF()
{
    if(free_block->next == NULL||
       free_block == NULL)
        return;
    empty_head_node.next = free_block;
    free_block_type *p,*x,*y,*f = NULL;
    while(f != empty_head_node.next->next){
        for(p = &empty_head_node; p->next->next != f; p = p->next){
            if(p->next->size > p->next->next->size){
                x = p->next;
                y = p->next->next;
                p->next = y;
                x->next = y->next;
                y->next = x;
            }
        }
        f = p->next;
    }

}
void rearrange_WF()
{
    if(free_block->next == NULL||
       free_block == NULL)
        return;

    empty_head_node.next = free_block;
    free_block_type *p,*x,*y,*f = NULL;
    while(f != empty_head_node.next->next){
        for(p = &empty_head_node; p->next->next != f; p = p->next){
            if(p->next->size < p->next->next->size){
                x = p->next;
                y = p->next->next;
                p->next = y;
                x->next = y->next;
                y->next = x;
            }
        
        }
        f = p->next;
    }

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
    printf("-----------------------------------------------------------------------\n");
    printf("\n Free memory:\n");
    printf("%20s %20s \n","    start_addr","    size");
    while(fbt != NULL){
        printf("%20d %20d\n",fbt->start_addr, fbt->size);
        fbt = fbt->next;
    }
    printf("\n Used memory:\n");
    printf("%10s %20s %10s %10s\n","pid","process_name","start_addr","size");
    while(ab != NULL){
        printf("%10d %20s %10d %10d\n",ab->pid,ab->process_name,ab->start_addr,ab->size);
        ab = ab->next;
    }
    printf("-----------------------------------------------------------------------\n");
    return 0;
}

int allocate_mem(allocated_block *ab)
{
    free_block_type *fbt, *pre;
    int requset_size = ab->size;
    fbt = pre = free_block;
    while(fbt){
        /*找到 并且剩余大*/
        if(fbt->size > requset_size && 
           fbt->size - requset_size > MIN_SLICE){
            fbt->size -= requset_size;
            ab->start_addr = fbt->start_addr;
            fbt->start_addr += requset_size;
            rearrange(ma_algorithm);
            return 1;
        /*找到 剩余小，直接分配整个*/
        }else if(fbt->size >= requset_size && 
                 fbt->size - requset_size < MIN_SLICE){
            while(pre->next != fbt) 
                pre = pre->next;
            pre->next = fbt->next;
            ab->start_addr = fbt->start_addr;
            ab->size  = fbt->size;
            free(fbt);
            rearrange(ma_algorithm);
            return 1;
        }else {
            fbt = fbt->next;
        }
    }
    fbt = free_block->next->next;
    pre = free_block->next;

    /*TO DO :利用内存紧缩再次查找*/
    /*
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
    */
    /*分配给进程内存失败     */  
    return -1;
}
allocated_block *find_process(int pid)
{
    allocated_block *object_process = alloc_phead;
    while(object_process->pid != pid &&
          object_process != NULL){
        object_process = object_process->next;
    }
    return object_process;

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

    pre = free_block;

    fbt->size = ab->size;
    fbt->start_addr = ab->start_addr;


    while(pre->next != NULL) 
        pre = pre->next;

    pre->next = fbt;
    fbt->next = NULL;

    pre = free_block;
    while(pre){
        printf("***%d\n",pre->start_addr);
        pre = pre->next;
        
    }

    sort_list_by_addr();
    merge_free_block();
    rearrange(ma_algorithm);
    return 1;
}
void merge_free_block()
{
    free_block_type *fbt,*pre = free_block;
    fbt = pre->next;
    while(fbt){
        if(pre->size + pre->start_addr == fbt->start_addr){
            pre->size += fbt->size;
            pre->next = fbt->next;
            free(fbt);
            fbt = pre->next;
            continue;
        }else{
            fbt = fbt->next;
            pre = pre->next;
        }
    }
}
void sort_list_by_addr()
{
    rearrange_FF();
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
void do_exit()
{
    allocated_block *p = alloc_phead;
    alloc_phead = alloc_phead->next;
    while(alloc_phead){
        free(p);
        p = alloc_phead;
        alloc_phead = alloc_phead->next;
    }
    free(p);

    free_block_type *q = free_block;
    free_block = free_block->next;
    while(free_block){
        free(q);
        q = free_block;
        free_block = free_block->next;
    }
    free(q);
}
void display_menu()
{
    //system("clear");
    printf("\n\n\n\n\n");
    printf("1-Set memory size (default = %d)\n",DEFAULT_MEM_SIZE);
    printf("2-Select memory alloction algorithm\n");
    printf("3-Create new process\n");
    printf("4-Terminate a process\n");
    printf("5-Display memory usage\n");
    printf("0-Exit\n");
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
            set_mem_size(); // 只能设置一次 通过flag判断
            break;
        case '2':
            set_algorithm(); // 设置算法
            flag = 1;
            break;
        case '3':
            new_process();// 新建进程
            flag = 1;
            break;
        case '4':
            kill_process(); // 杀死进程
            flag = 1;
            break;
        case '5':
            puts("case 5\n");
            display_mem_usage(); // 显示内存分配情况
            flag = 1;
            break ;
        case '0':
            do_exit(); // 退出
            exit(0);
        }
    }

}
