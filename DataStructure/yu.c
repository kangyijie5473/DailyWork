#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node *key;
typedef struct Node{
    char data;
    struct Node *leftChild;
    struct Node *rightChild;
}node;
node *mykey;
char *ch;
int count;

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
void changeChildren(node *root)
{
    if(root == NULL)
        return;
    changeChildren(root->leftChild);
    changeChildren(root->rightChild);
    if(root->rightChild && root->leftChild){
        node * temp = root->leftChild;
        root->leftChild = root->rightChild;
        root->rightChild = temp;
        return;
    }else if(root->rightChild == NULL && root->leftChild == NULL)
        return;
    if(root->leftChild)
        root->rightChild = root->leftChild,root->leftChild = NULL;
    else
        root->leftChild = root->rightChild,root->rightChild  = NULL;
}
int main(void)
{
    node root;
    node *Root;
    
    char a[20];
    scanf("%s",a); // put in pre list
    ch = &a[0];

    mykey = &root;
    createTree(&root); // creat tree
 

    changeChildren(&root);
    prePrint(&root); // pre traversal print
    printf("\n");

    midPrint(&root); // mid traversal print
    printf("\n");

    lastPrint(&root);// last traversal print

    
}
