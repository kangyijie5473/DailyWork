#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Opera{
	char element;
	struct Opera *next;
}opera;

typedef struct Number{
	float element;
	struct Number *next;
}number;

opera pHeadOpera,*operaStackTop = NULL;
number pHeadNumber,*numberStackTop = NULL;


float add(float a, float b){
        return a+b;    

}
float sub(float a,float b){
        return a-b;

}
float mul(float a, float b){
        return a*b;    

}
float my_div(float a, float b){
        return a/b;

}

float (*oper_fun[])(float a, float b) = {add, sub, mul, my_div};


void pushOpera(char oper)
{
	opera *pnew;
	pnew = (opera *)malloc(sizeof(opera));
	pnew->element = oper;
	pHeadOpera.next = pnew;
	pnew->next = operaStackTop;
	operaStackTop = pnew;
	return;
}

void pushNumber(float num)
{
	number *pnew;
	pnew = (number *)malloc(sizeof(number));
	pnew->element = num;
	pHeadNumber.next = pnew;
	pnew->next = numberStackTop;
	numberStackTop = pnew;
	return;
}

float popNumber(void)
{	
	float x;
	x = numberStackTop->element;
	numberStackTop = numberStackTop->next;
	pHeadNumber.next = numberStackTop;
	return x;
}

char popOpera(void)
{	
	char  x;
	x = operaStackTop->element;
	operaStackTop = operaStackTop->next;
	pHeadOpera.next = operaStackTop;
	return x;
}

char frontOpera(void)
{
    char x;
    x = operaStackTop->element;
    return x;
}

void change(char str[])
{
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '#'){
            str[i] = 'A';
        }
        if(str[i] == '+'){
            str[i] = 'B';
        }
        if(str[i] == '-'){
            str[i] = 'C';
        }
        if(str[i] == '*'){
            str[i] = 'D';
        }
        if(str[i] == '/'){
            str[i] = 'E';
        }
    }
}


int main(void)
{
	char str[20];
    char s[20];
	char op,tem;
    int k = 0;
    float result;
    float b,a;
    pHeadOpera.next = NULL;
    pHeadNumber.next = NULL;
	str[0] = '#';
	scanf("%s",s);
    strcat(str,s);
	str[strlen(str) +1] = '\0';
	str[strlen(str) ] = '#';
    change(str);
    pushOpera(str[k++]);
    while(1){
        if(str[k] >= '0' && str[k] <= '9'){
            pushNumber(str[k++] - '0');
            continue;
        }else {
            if(str[k] == 'A' && frontOpera() == 'A'){
                break;
            }
            if(str[k] <= (tem = frontOpera() ) ){
                b = popNumber();
                a = popNumber();
                op = popOpera();
                result = oper_fun[op - 'A' -1 ](a, b);
                pushNumber(result);
                continue;
            }else{
                pushOpera(str[k++]);
                continue;
            }
        }
    }
    
    printf("result is %f\n",result = popNumber());
	return 0;

}

