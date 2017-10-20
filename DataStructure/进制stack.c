/*
 * > File Name: jinzhi.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月20日 星期五 11时31分58秒
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack{
    char buffer[100];
    int top;
};
int isFull(struct Stack *stack)
{
    if(stack->top == 100)
        return 1;
    else
        return 0;
}
int isEmpty(struct Stack *stack)
{
    if(stack->top == 0)
        return 1;
    else
        return 0;
}
char pop(struct Stack *stack)
{
    return stack->buffer[--stack->top];
}
void push(char c, struct Stack *stack)
{
    stack->buffer[stack->top++] = c;
    
}
char getStackTop(struct Stack *stack)
{
    int i = stack->top - 1;
    return stack->buffer[i];
}
int main(void)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = 0;

    for(int i = 0; i < 5; i++){
        int a;
        scanf("%d",&a);
        if(a == 0){
            printf("0\n");
            continue;
        while(a){
        }
            if(a%2 == 0)
                push('0',stack);
            else
                push('1',stack);
            a = a/2;
        }
        while(!isEmpty(stack))
            printf("%c",pop(stack));
        if(i != 4)
            printf("\n");
    }
    free(stack);
}
