#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
using namespace std;
typedef struct Node{
    char data;
    struct Node *leftChild;
    struct Node *rightChild;
}node;


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
void noRecursizePreVisit(node *root)
{
    stack<node *> st;
    while(root || !st.empty()){
        if(root){
            cout << root->data;
            st.push(root);
            root = root->leftChild;
        }else if(!st.empty()){
            root = st.top();
            st.pop();
            root = root->rightChild;
        }
    }
}
void noRecursizeMidVisit(node *root)
{
    
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



int main(void)
{
    node root;
    
    char a[20];
    scanf("%s",a); // put in pre list
    ch = &a[0];

    createTree(&root); // creat tree


    prePrint(&root); // pre traversal print
    printf("\n");

    //noRecursizePreVisit(&root);
    printf("\n");
    // midPrint(&root); // mid traversal print
    // printf("\n");

    // lastPrint(&root);// last traversal print

    
}
