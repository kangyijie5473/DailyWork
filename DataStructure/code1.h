/*************************************************************************
	> File Name: code1.h
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2016年12月27日 星期二 09时14分22秒
 ************************************************************************/

#ifndef _CODE1_H
#define _CODE1_H
#define TRUE 1
#define FALSE 0
#define CODE  2
#define JIEMA 3
#define MAXLEN 256
typedef struct {
    int parent;
    int leftChild;
    int rightChild;
    float weight;
}node;
FILE *deCpsFp;
void getChar();
int fileToBuffer();
unsigned char fileWeight[256];
char deFile[MAXLEN];
char zeroNum;
int root;
int effectiveChar;
char compressFile[MAXLEN];
FILE *compressfp;
char *codeBuffer;
node treeNode[512];
FILE *chooseFile();
int getWeight(FILE *fd);
int creatTree();
void reverseCode(char huffmanCode[], int pos);
void findMinWeight(int n, int *node1, int  *node2);
void getCode(unsigned char i, char huffmanCode[]);
int spiltBuffer();
unsigned char ctoi(char buffer[]);
void saveTree();
#endif
