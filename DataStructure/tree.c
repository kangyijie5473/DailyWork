/*************************************************************************
	> File Name: tree.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月25日 星期二 17时29分17秒
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct Node{
    char data;
    struct Node *leftChild;
    struct Node *rightChild;
}node;

typedef struct  StackNode
{
	node treeNode;
	struct  StackNode *next;
}stackNode;

char *ch;
int count;
stackNode *top;
stackNode head;

int judgeEmpty(void){
	if(top == NULL){
		return -1;
	}else {
		return 1;
	}
}
void push(node *p)
{
    stackNode *q;
    q = (stackNode *)malloc(sizeof(stackNode));
    memcpy(&(q->treeNode), p, sizeof(node));
    head.next = q;
    q->next = top;
    top = head.next;
    
}

node* pop(void)
{
    node *t;
    t = (node *)malloc(sizeof(top->treeNode));
    node *temp = &(top->treeNode);
    memcpy(t, temp, sizeof(top->treeNode));
    top = top->next;
    head.next = top;
    return t;
    
}

void funMidPrint(node *root)
{
    node *p = root;
    top = NULL;
    int i;
    while(p != NULL || (i = judgeEmpty()) != -1){
        while(p != NULL){
            push(p);
            p = p->leftChild;
        }
        if((i = judgeEmpty()) != -1){
            p = pop();
            printf("%c",p->data);
            p = p->rightChild;
        }
    }
}

void prePrint(node *root)
{
	if(root == NULL)
		return;
	printf("%c", root->data);
	prePrint(root->leftChild);
	prePrint(root->rightChild);
}

void midPrint(node *root)
{
	if(root == NULL)
		return;
	midPrint(root->leftChild);
	printf("%c", root->data);
	midPrint(root->rightChild);
}

void lastPrint(node *root)
{
	if(root == NULL)
		return;
	lastPrint(root->leftChild);
	lastPrint(root->rightChild);
	printf("%c", root->data);
}

node *createTree(node *root)
{
    if(*ch == '#'){
        ch++;
        root = NULL;
        return root;
    }else{
    	if(count++){
        	root = (node *)malloc(sizeof(node));
    	}
        root->data = *(ch++);
        root->leftChild = createTree(root->leftChild);
        root->rightChild = createTree(root->rightChild);
        return root;
        
    }
}

void printTree(node *root,int h)
{
	int i ;
    if(root == NULL){
        return ;
    }
    printTree(root->rightChild, h+1);
    for(i = 1; i <= h; i++){
        printf("   ");
    }
    printf("%c\n",root->data);
    printTree(root->leftChild,h+1);
}

int main(void)
{
    node root;
    node *Root;
    char a[20];
    scanf("%s",a);
    ch = &a[0];
    createTree(&root);
    printTree(&root, 1);
    prePrint(&root);
    printf("\n");
    midPrint(&root);
    printf("\n");
    lastPrint(&root);
    printf("\n\n");
    funMidPrint(&root);
}
