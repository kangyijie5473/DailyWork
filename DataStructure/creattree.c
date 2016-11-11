/*************************************************************************
	> File Name: creattree.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月30日 星期日 15时34分21秒
 ************************************************************************/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct Node{
    char data;
    struct Node *leftChild;
    struct Node *rightChild;
}node;
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
node *anotherCreatTree(node *root, char a[], char b[], int len)
{
    if(len <= 0){
        return root = NULL;
    }else{
        char *temp = NULL;
        int k = 0;
        root = (node *)malloc(sizeof(node));
        root->data = *a;
        for(temp = b; *temp != *a; temp++){
            k++;
        }
        root->leftChild = anotherCreatTree(root->leftChild, a+1, b, k);
        root->rightChild = anotherCreatTree(root->rightChild, a+1+k, temp+1, len-1-k);
        return root;
    }

}
int main(void)
{
    char b[64];
    char c[64];
    node *anotherRoot = NULL;
    scanf("%s",b);
    scanf("%s",c);
    anotherRoot = anotherCreatTree(anotherRoot, b, c, strlen(b));
    printTree(anotherRoot,1);
    
}
