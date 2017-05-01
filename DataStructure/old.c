#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 40
#define ALL 1
typedef struct  {
    int parent;
    int leftChild;
    int rightChild;
    int weight;
}Huffmantree;

char objCharacter[20];
char *character;
Huffmantree huffmantree[N];

void findMinWeight(int n, int *node1, int *node2)
{
    int i,temp = 100;	
    for(i = n; i >= 1; i--){
        if(huffmantree[i].parent == 0 && 
           huffmantree[i].weight <= temp){
               *node1 = i;
               temp = huffmantree[i].weight;
           }
    }
    temp = 100;
    for(i = n; i >= 1; i--){
        if(huffmantree[i].parent == 0 && 
           i != *node1 &&
           huffmantree[i].weight <= temp){
               *node2 = i;
               temp = huffmantree[i].weight;
           }
    }
}
void print(int n)
{
    int i;
    for(i = 1; i <= n; i++){
        printf("NO.%d weight%d parent%d,leftChild%d rightChild%d\n", i, huffmantree[i].weight,
               huffmantree[i].parent,
               huffmantree[i].leftChild,
               huffmantree[i].rightChild);
    }
}
void reverseCode(char huffmanCode[], int pos)
{
    char *h,*t;
    char temp;
    h = &huffmanCode[0];
    t = &huffmanCode[pos];
    while(h != t && h < t){
        temp = *h;
        *h = *t;
        *t = temp;
        h++;
        t--;
    }
}
void getChar(char objCode[], char resultChar[],int n)
{
    int i = n;
    char *p = &objCode[0];
    char *q = &resultChar[0];
    while(*p != '\0'){
        while(huffmantree[i].leftChild != 0 || huffmantree[i].rightChild != 0){
            if(*p == '0'){
                i = huffmantree[i].leftChild;
                p++;
            }else{
                i = huffmantree[i].rightChild;
                p++;
            }
        }
        *q = character[i];
        q++;
        i = n;
    }
    *q = '\0';
}
void getCode(int i, char huffmanCode[])
{
    int pos = 0;
    int temp;
    while(huffmantree[i].parent != 0){
        temp = huffmantree[i].parent;
        if(huffmantree[temp].leftChild == i){
            huffmanCode[pos++] = '0';
        }else{
            huffmanCode[pos++] = '1';
        }
        i = temp;
    }
    huffmanCode[pos] = '\0';
    reverseCode(huffmanCode,pos-1);
}
void getKey(int *key, int i)
{
    int j = 1;
    while(character[j++] != objCharacter[i])
    ;
    j--;
    *key = j;

}
void printCode(int n, int flag)
{
    int i;
    int key;
    char huffmanCode[20];
    if(flag == ALL){	
        for(i = 1; i <= n; i++){
            getCode(i, huffmanCode);
            printf("%c --> %s\n",character[i],huffmanCode);
            memset(huffmanCode, 0, sizeof(huffmanCode));
        }
    }else{
        for(i = 0; i < strlen(objCharacter); i++){
            getKey(&key,i);
            getCode(key, huffmanCode);
            printf("%s",huffmanCode);
            memset(huffmanCode, 0, sizeof(huffmanCode));
        }
        printf("\n");
    }	
}
void creatHuffmanTree(int weight[], int n)
{
    int i ;
    int m = 2*n-1;
    for(i = 1; i <= n; i++){
        huffmantree[i].weight = weight[i];
        huffmantree[i].rightChild = 0;
        huffmantree[i].leftChild=0;
        huffmantree[i].parent = 0;
    }
    for(i = n+1; i <= m; i++){
        int node1,node2,temp;
        findMinWeight(i-1, &node1, &node2);
        huffmantree[i].weight = huffmantree[node1].weight + huffmantree[node2].weight;
        huffmantree[i].leftChild = node1;
        huffmantree[i].rightChild = node2;
        huffmantree[node1].parent = i;
        huffmantree[node2].parent = i;		
    }
    //print(m);
}
int main(void)
{
    int choice;
    int n;
    int weight[200];
    char resultChar[20];
    char objCode[100];
    printf("请输入字符集个数\n");
    scanf("%d",&n);

    character = (char *)malloc(sizeof(char) * (n+2));
    printf("请输入字符集\n");
    scanf("%s",character+1);

    int i;
    printf("请输入权值\n");
    for(i = 1; i <= n; i++){
        scanf("%d",&weight[i]);
    }
    creatHuffmanTree(weight, n);
    printCode(n,ALL);

    printf("输入要编码的字符串\n");
    scanf("%s",objCharacter);
    printCode(n,0);

    printf("输入要解码的字符串\n"); 
    scanf("%s",objCode);
    getChar(objCode, resultChar, 2*n-1); 
    printf("result -> %s\n",resultChar); 
}
