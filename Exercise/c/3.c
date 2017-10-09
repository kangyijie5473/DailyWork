#include <stdio.h>
#include <stdlib.h>
struct List{
    int element;
    struct List *next;
};
struct List *initList(int num)
{
    struct List *head ;
    struct List *new ,*tail = NULL;
    head = tail;
    int temp;
    while(num--){
        scanf("%d",&temp);
        new = (struct List *)malloc(sizeof(struct List));
        new->element = temp;
        new->next = NULL;
        if(!head)
            head = tail = new;
        else{
            tail->next = new;
            tail = tail->next;
        }
    }
    return head;
}
void deleteToInsert(struct List *pa, struct List *pb, int i, int len, int j)
{
    struct List *tempA ;
    while(--i){
        pa = pa->next;
        if (i!= 1)
            tempA = pa;
    }
    
    while(--j){
        pb = pb->next;
    }
    struct List *tempB = pb->next;
    pb->next = pa;
    len--;
    while(len--){
        pa = pa->next;
    }
    tempA->next = pa->next;
    pa->next = tempB;
}
void print(struct List *p){
    while(p){
        printf("%d",p->element);
        if(p->next)
            printf(" \n");
        p = p->next;
    }
    printf("\n");
}
int main(void)
{
    int i,len,j;
    struct List *pa = initList(10);
    struct List *pb = initList(6);
    scanf("%d%d%d",&i,&len,&j);
    deleteToInsert(pa, pb, i, len, j);
    printf("la:");
    print(pa);
    printf("lb:");
    print(pb);
    printf("la:1 2 3 7 8 9 10\nlb:10 20 30 4 5 6 40 50 60\n");
}
