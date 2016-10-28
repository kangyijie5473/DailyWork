#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct Node{
    char data;
    int flag;
    struct Node *next;
}node;
node *Pre;
node  *initTree(void)
{
	char ch;
	node *phead,*pnew,*pend;

	pnew = (node *)malloc(sizeof(node));
	pend = phead = pnew;
	phead->flag = 1;
	phead->next = NULL;
	while(1){
		scanf("%c",&ch);
		if(ch == '*'){
            pnew =(node *)malloc(sizeof(node));
            pnew->next = NULL;
            pnew->flag = 0;
            pend->next = pnew;
			return phead;
		}
		if(ch == '\n')
			continue;
		pnew = (node *)malloc(sizeof(node));
		pnew->data = ch;
		pnew->flag = 0;
		pnew->next = NULL;
		pend->next = pnew;
		pend = pend->next;

	}
}
node *findRoot(node *ptemp, char preChar)
{
	while(ptemp->data != preChar){
		Pre = Pre->next;
		ptemp = ptemp->next;
		printf("%c %c\n",ptemp->data, preChar);
	}
	return ptemp;
}
int judge(node *midTemp, node *preTemp)
{
	int i;
	node *ptemp;
	if(Pre->flag == 0 && midTemp->next->flag == 0){
		midTemp->flag = 1;
		return 1;
	}else if(Pre->flag == 1 && midTemp->next->flag == 1){
		midTemp->flag = 1;
		for(i = 0; i < 2; i++){
			ptemp = (node *)malloc(sizeof(node));
			ptemp->data = '#';
			ptemp->flag = 1;
			ptemp->next = preTemp->next;
			preTemp->next = ptemp;
		}
	}else{
		midTemp->flag = 1;
		for(i = 0; i < 1; i++){
			ptemp = (node *)malloc(sizeof(node));
			ptemp->data = '#';
			ptemp->flag = 1;
			ptemp->next = preTemp->next;
			preTemp->next = ptemp;
		}
	}
}	

	

void fun(node *preHead, node *midHead)
{
	int i;
	node *preTemp = preHead->next;
	node *midTemp = Pre = midHead;
	while(preTemp->next != NULL){
		printf("!\n");
        midTemp = midHead->next;
		Pre = midHead;
		if(preTemp->data == '#'){
			printf("@\n");
			preTemp = preTemp->next;
			continue;
		}
		printf("#\n");
		printf("%c\n", preTemp->data);
		midTemp = findRoot(midTemp, preTemp->data);
		printf("$\n");
		if((i = judge(midTemp, preTemp)) == 1){
			printf("^\n");
			preTemp = preTemp->next;
			continue;
        }else{
            preTemp = preTemp->next;
        }
	}
}
void test(node *phead)
{
	node *ptemp = phead->next;
	while(ptemp != NULL){
		printf("%c", ptemp->data);
		ptemp = ptemp->next;
	}
	printf("\n");
}
int main(void)
{
	node *preHead;
	node *midHead;
	preHead = initTree();
	test(preHead);
	midHead = initTree();
	test(midHead);
	fun(preHead,midHead);
	test(preHead);
	
}
