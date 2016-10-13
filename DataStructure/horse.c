#include <stdio.h>
#include <stdlib.h>

#define MAX 7
#define MIN 0

int map[8][8];
int count = 1;
typedef struct  Node
{
	int i;
	int j;
	struct Node *next;
}node;
node head;
node *stackTop = NULL;
void run();

void pushStack(int i, int j)
{
	node *pnew;
	pnew  = (node *)malloc(sizeof(node));
    pnew->i = i;
    pnew->j = j;
	head.next = pnew;
	pnew->next = stackTop;
	stackTop = pnew;
	return ;
}

void popStack(void)
{
	node *ptemp = stackTop;
	stackTop = stackTop->next;
	free(ptemp);
	head.next = stackTop;
	return ;
}

void fun(int i, int j)
{
	map[i][j] = 1;
    printf("No.%d(%d,%d)\n",count++,i,j);
	pushStack(i, j);
	run();
	popStack();
	return;
}
void run(void)
{
	int a = stackTop->i,b = stackTop->j;
	if(a - 2 >= MIN && b + 1 <= MAX && map[a-2][b+1] == 0){
		fun(a-2, b+1);
	}
	if(a - 2 >= MIN && b - 1 >= MIN && map[a-2][b-1] == 0){
		fun(a-2, b-1);
	}
	if(a - 1 >= MIN && b + 2 <= MAX && map[a-1][b+2] == 0){
		fun(a-1, b+2);
	}
	if(a - 1 >= MIN && b - 2 >= MIN && map[a-1][b-2] == 0){
		fun(a-1,b-2);
	}
	if(a + 1 <= MAX && b + 2 <= MAX && map[a+1][b+2] == 0){
		fun(a+1,b+2);
	}
	if(a + 1 <= MAX && b - 2 >= MIN && map[a+1][b-2] == 0){
		fun(a+1,b-2);
	}
	if(a + 2 <= MAX && b + 1 <= MAX && map[a+2][b+1] == 0){
		fun(a+2,b+1);
	}
	if(a + 2 <= MAX && b - 1 >= MIN && map[a+2][b-1] == 0){
		fun(a+2,b-1);
	}
	return;
}

int main(void)
{
	int i,j;
	scanf("%d%d",&i,&j);
	fun(i,j);
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
