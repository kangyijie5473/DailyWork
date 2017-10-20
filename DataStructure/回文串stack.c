/*
 * > File Name: huiwen.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月20日 星期五 12时40分32秒
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
    struct Stack *stack  = (struct Stack *)malloc(sizeof(struct Stack));
    memset(stack, 0, sizeof(struct Stack));
    char inBuffer[100];
    scanf("%s",inBuffer);
    int len = strlen(inBuffer);
    for(int i = 0; i < len / 2; i++)
        push(inBuffer[i],stack);
    if(len % 2)
    {
        for(int i = len / 2 + 1; i < len; ++i)
            if(inBuffer[i] != pop(stack)){
                printf("不是回文\n");
                break;
            }
    }
    else
    {
        for(int i = len / 2; i < len; ++i)
            if(inBuffer[i] != pop(stack)){
                printf("不是回文\n");
                break;
            }
    }
    if(isEmpty(stack)) 
        printf("回文\n");
    free(stack);
}
