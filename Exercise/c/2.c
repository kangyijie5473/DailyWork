#include <stdio.h>
#include <stdlib.h>
struct List{
    int element;
    struct List *next;
};
struct List *initList(int num)
{
    struct List *head = (struct List *)malloc(sizeof(struct List));
    struct List *new ,*tail = NULL;
    tail = head;
    int temp;
    while(num--){
        scanf("%d",&temp);
        new = (struct List *)malloc(sizeof(struct List));
        new->element = temp;
        new->next = NULL;
        tail->next = new;
        tail = tail->next;
    }
    return head;
}
struct List *mergeList(struct List *headA, struct List *headB)
{
    struct List *pa = headA->next;
    struct List *pb = headB->next;
    struct List *ptemp,*phead = (struct List *)malloc(sizeof(struct List));
    ptemp = phead;
    while(pa && pb){
        if(pa->element > pb->element){
            ptemp->next = pb;
            pb = pb->next;
        }else{
            ptemp->next = pa;
            pa = pa->next;
        }
        ptemp = ptemp->next;
    }
    if(pa){
        ptemp->next = pa;
    }else{
        ptemp->next = pb;
    }
    return phead;
}
int main(void)
{
    struct List *pa = initList(6);
    struct List *pb = initList(9);
    struct List *pc = mergeList(pa, pb);
    pc = pc->next;
    while(pc){
        printf("%d ",pc->element);
        pc = pc->next;
    }
}
