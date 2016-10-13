/*************************************************************************
	> File Name: set.c
	> Author: Jack Kang
	> Mail: xiyoulinux.kangyijie@gmail.com
	> Created Time: 2016年09月07日 星期三 09时53分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define SAME 1
#define DIFF 0
typedef struct Node{
    char element;
    int flag;
    struct Node *next;
}node;

void mul(node *pHeadA, node *pHeadB)
{
    node *pB;
    node *pA;
    pA = pHeadA -> next;
    while(pA){
        pB = pHeadB -> next;
        while(pB){
            if(pB -> element == pA -> element){
                pA -> flag = SAME;
                break;
            }
            pB = pB -> next;
        }
        pA = pA -> next;
    }
    printf("A*B =\n");
    pHeadA = pHeadA -> next;
    while(pHeadA){
        if(pHeadA -> flag == SAME){
            printf("%c\n",pHeadA -> element);
        }
        pHeadA = pHeadA -> next;
    }
    return ;
}
void add(node *pHeadA, node *pHeadB)
{
    node *pB;
    node *pA;
    pA = pHeadA -> next;
    while(pA){
        pB = pHeadB -> next;
        while(pB){
            if(pB -> element == pA -> element){
                pB -> flag = SAME;
                break;
            }
            pB = pB -> next;
        }
        pA = pA -> next;
    }
    printf("A+B =\n");
    pHeadA = pHeadA -> next;
    while(pHeadA){
        if(pHeadA -> flag == SAME){
            pHeadA = pHeadA -> next;
            continue;
        }
        printf("%c\n",pHeadA -> element);
        pHeadA = pHeadA -> next;
    }
    pHeadB = pHeadB -> next;
    while(pHeadB){
        if(pHeadB -> flag == SAME){
            pHeadB = pHeadB -> next;
            continue;
        }
        printf("%c\n",pHeadB -> element);
        pHeadB = pHeadB -> next;
    }
   
    printf("\n");
    return ;
}


void sub(node *pHeadA, node *pHeadB)
{
    node *pB;
    node *pA;
    pA = pHeadA -> next;
    while(pA){

        pB = pHeadB -> next;
        while(pB){
            if(pB -> element == pA -> element){
                pA -> flag = SAME;
                break;
            }
            pB = pB -> next;
        }
        pA = pA -> next;
    }
    printf("A-B =\n");
    pHeadA = pHeadA -> next;
    while(pHeadA){
        if(pHeadA -> flag == SAME){
            pHeadA = pHeadA -> next;
            continue;
        }
        printf("%c\n",pHeadA -> element);
        pHeadA = pHeadA -> next;
    }
    return ;
}
void print(node *pHeadA){
   pHeadA = pHeadA -> next;
    while(pHeadA){
        printf("%c\n",pHeadA -> element);
        pHeadA = pHeadA -> next;
    }
  
}
  
node *creat(void)
{
    node *pHead;
    node *pEnd;
    node *pNew;
    char temp = '1';

    pNew = (node *)malloc(sizeof(node));
    pEnd = pHead = pNew;
    pNew -> next = NULL;
    
    do{
        scanf("%c",&temp);
        if(temp == '0'){
            break;
        }
        if(temp == '\n'){
            continue;
        }
        pNew = (node *)malloc(sizeof(node));
        pNew -> element = temp;
        pNew -> next = NULL;
        pEnd -> next = pNew;
        pEnd = pNew;
    }
    while(1);
    return pHead;
}

void (*operation[])(node *pHeadA, node *pHeadB) = {sub, add, mul};

int main(void)
{
    node *pHeadA,*pHeadB;
    int choice;
    printf("请选择你想完成的集合运算\n");
    printf("1.A-B\n2.A+B\n3.A*B\n");
    scanf("%d",&choice);
    printf("请输入集合A中的元素，以0结束\n");
    pHeadA = creat();
    print(pHeadA);
    printf("请输入集合B中的元素，以0结束\n");
    pHeadB = creat();
    print(pHeadB);
   
    operation[choice -1](pHeadA,pHeadB);
    return 0;
}







