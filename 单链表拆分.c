#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

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
        pend = pend -> next;
    }
    return phead;
}

node *divide(node *phead)
{
	node *p,*q,*pend,*pHead,*ptempend;
	node *ptemp = phead;
	ptempend =ptemp;
	pend = pHead = (node *)malloc(sizeof(node));
	p = ptemp -> next;
	ptemp -> next = NULL;
	q = p -> next;
	while(p){
		if(p -> data > ptemp -> data){
			ptempend -> next = p;
			ptempend = ptempend -> next;
			p -> next = NULL;
			p = q;
			if(!p)
				break;
			q = q ->next;
		}else{
			pend -> next = p;
			pend = pend -> next;
			p -> next = NULL;
			p = q;
			if(!p)
				break;
			q = q ->next;
		}
	}
	pend -> next = ptemp;
	return pHead;
}
void print(node *phead)
{
    node *ptemp = phead -> next;
    while(ptemp){
        printf("%d\n",ptemp -> data);
        ptemp = ptemp -> next;
    }
    return ;
}
int main(void)
{
	int n;
	node *phead;
	printf("请输入链表的项数\n");
	scanf("%d",&n);
	phead = create(n);
	//print(phead);
	printf("\n\n");
	phead = divide(phead);
	print(phead);
}
