/*
 * > File Name: kuohao.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月20日 星期五 10时54分54秒
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
    char inBuffer[100];
    struct Stack *stack;
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = 0;
    scanf("%s",inBuffer);
    int len = strlen(inBuffer);
    for(int i = 0; i < len; i++){
        if(!isFull(stack) && (inBuffer[i] == '[' || inBuffer[i] == '{' || inBuffer[i] == '('))
            push(inBuffer[i], stack);
        if(!isEmpty(stack) && (inBuffer[i] == getStackTop(stack) + 1 || inBuffer[i] == getStackTop(stack) + 2))
            pop(stack);
    }
    if(isEmpty(stack))
        printf("match\n");

    free(stack);

}
