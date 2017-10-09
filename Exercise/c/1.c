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
int findK(struct List *head, int k)
{
    struct List *p = head->next;
    int length = 0;
    while(p){
        length++;
        p = p->next;
    }
    if(k > length)
        return 0;
    int index = length - k;
    p = head->next;
    while(index--){
        p = p->next;
    }
    printf("%d\n",p->element);
    return 1;
}
int main(void)
{
    struct List *list = initList(9);
    int k;
    scanf("%d",&k);
    return findK(list, k);
}

