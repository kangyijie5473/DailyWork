#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}node;
void print(node *phead)
{
    int i;
    node *ptemp = phead ;
    for(i = 4 ; i >= 0; i--){
        printf("%d\n",ptemp -> data);
        ptemp = ptemp -> next;
    }
    /*
     while(ptemp){
        printf("%d\n",ptemp -> data);
        ptemp = ptemp -> next;
    }
        */
    return ;
}
node *create(int n)
{
    node *phead, *pnew,*pend;
    int i;
    pnew = (node *)malloc(sizeof(node));
    pnew -> next = NULL;
    pend = phead = pnew;
    printf("NO 1:\n");
    scanf("%d", &phead -> data);
    for(i = 2; i <= n; i++){
        pnew = (node *)malloc(sizeof(node));
        pend -> next = pnew;
        pnew -> next = NULL;
        printf("NO %d:\n",i);
        scanf("%d",&pnew -> data);
        pnew -> data = i;
        pend = pend -> next;
    }
    pend -> next = phead;
    return phead;
}

void out(node *phead,int m)
{
    int i;
    node *pre = phead;
    while(phead ->next != phead){
        for(i = 1; i < m -1; i++){
            pre = pre ->next;
            phead = phead -> next;
        }
        phead = phead -> next;
        printf("%d\n", m = phead -> data);
        phead = phead -> next;
        pre -> next = phead;
    }
    printf("final%d\n",phead -> data);
    return ;
}
int main(void)
{
    node *phead;    
    int n,m;
    printf("输入人数和初始次数");
    scanf("%d%d",&n,&m);
    phead = create(n);
    //print(phead);
    out(phead, m);
}
