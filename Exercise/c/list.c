/*************************************************************************
	> File Name: quick.c
	> Author: Jack Kang
	> Mail: xiyoulinux.kangyijie@gmail.com
	> Created Time: Fri May  5 10:41:57 2017
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define N 30
typedef struct Node{
    int k;
    struct Node *next;

}node;

int list_init_head(node *head)
{
    node *pNew;
    while(1){
        int temp;
        scanf("%d",&temp);
        if(temp == 0 ) break;
        pNew = (node *)malloc(sizeof(node));
        pNew->k = temp;
        pNew->next = head->next;
        head->next = pNew;
    }
    
}

int list_init_tail(node *head)
{
    node *pNew;
    node *pEnd = head;
    while(1){
        int temp;
        scanf("%d",&temp);
        if(temp == 0 ) break;
        pNew = (node *)malloc(sizeof(node));
        pNew->k = temp;
        pEnd->next = pNew;
        pNew->next = NULL;
        pEnd = pEnd->next;
    }
    
}
void list_reverse(node *head)
{
    node *ptemp ;
    node *p = head->next;
    head->next = NULL;
    while(p){
        ptemp = p;
        p = p->next;
        ptemp->next =  head->next;
        head->next =  ptemp;
    }
}
void print_list(node *phead)
{
    while(phead){
        printf("%d\n",phead->k);
        phead = phead->next;
    }
}
node *top;
void pop(node *head)
{
    head->next = top->next;
    free(top);
    top = head->next;
}
void push(node *head)
{
    
}
int main(void)
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    list_init_head(head);
    print_list(head->next);
    top = head->next;
    pop(head);
    print_list(head->next);
    //list_reverse(head);

}
