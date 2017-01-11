/*************************************************************************
	> File Name: graph.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2016年12月09日 星期五 12时24分24秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXLEN 6
typedef struct Node{
    struct Node* next;
    int element;
}node;
void getInOut(void);
void init(void);
void getlist(void);
void dfs(void);
void push(node *temp);
node *pop(void);
void bfs(void);
int matrix[MAXLEN][MAXLEN] = {0,0,0,0,0,0,
                               0,0,1,0,0,1,
                               0,0,0,1,0,0,
                               0,0,0,0,1,0,
                               0,1,1,0,0,0, 
                               0,0,0,1,0,0};

node list[MAXLEN];
node *stack[MAXLEN];
int top;

int main(void)
{
    init();
    getInOut();
    getlist();
    dfs();
}

void getlist(void)
{
    node *temp;
    for(int i = 1; i < MAXLEN; i++){
        for(int j = 1; j < MAXLEN; j++){
            if(matrix[i][j] == 1){
                temp = (node *)malloc(sizeof(node));
                temp->element = j;
                temp->next = list[i].next;
                list[i].next = temp;
            }
        }
    }

}

void bfs(void)
{
    int str[MAXLEN],count = 1;
    int *index;
    node *p;
    puts("please put your first point");
    str[count++] = getchar();
    index = &str[0];
    list[str[1]-'a'+1].element = 0;
    while(count != MAXLEN){
        index++;
        p = list[*index-'a'+1].next;
        while(p != NULL){
            if(list[p->element].element == 0){
                p = p->next;
                continue;
            }
            str[count++] = p->element+'a'-1;
            list[p->element].element = 0;
            p = p->next;
        }
    }
    printf("bfs result:");
    for(int i = 1; i < MAXLEN; i++){
        printf("%c",str[i]);
    }
    puts("");
}
void push(node *temp)
{
    top++;
    stack[top] = temp;
}
node *pop(void)
{
    top--;
    //printf("stack->%c\n",stack[top+1]->element);
    return stack[top+1];
}
void dfs(void)
{
    node *p;
    char temp;
    int str[MAXLEN],count = 1;
    puts("please choose your first point");
    temp = getchar();
    p = &list[temp-'a'+1];
    while(count != MAXLEN){
        if(p->element != 0){
            push(p);
            //printf("%c\n",p->element);
            str[count++] = p->element;
            p->element = 0;
        }else{
            //printf("1pop->%d\n",p->element);
            p = pop();
            p = p->next; 
            //printf("2pop->%c\n",p->element);
        }
        p = p->next;
        if(p == NULL){
            p = pop();
            //printf("pop2 -> %c\n",p->element);
            p = p->next->next;
        }
        p = &list[p->element];
    }
    printf("dfs result:");
    for(int i = 1; i < MAXLEN; i++){
        printf("%c",str[i]);
    }
    puts("");
    
    
}

void init(void)
{
    for(int i = 1; i < MAXLEN; i++){
        list[i].element = getchar();
        list[i].next = NULL;
    }
    getchar();
   /* printf("matrix:\n");
    for(int i = 1; i < MAXLEN; i++){
        printf("%d:\n",i);
        scanf("%d%d%d%d%d",&matrix[i][1],&matrix[i][2],
            &matrix[i][3],&matrix[i][4],&matrix[i][5]);
    }*/   
}

void getInOut(void)
{
    int inCount = 0,outCount = 0;
    for(int i = 1; i < MAXLEN; i++){
        for(int k = 1; k < MAXLEN; k++){
            outCount += matrix[i][k];
            inCount += matrix[k][i];
        }
        printf("%c ,out:%d,in:%d,sum:%d\n",list[i].element,outCount,inCount,outCount+inCount);
        outCount = 0;
        inCount = 0;
    }
}
