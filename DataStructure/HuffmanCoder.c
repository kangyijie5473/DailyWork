/*************************************************************************
	> File Name: HuffmanCoder.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2016年12月24日 星期六 10时30分29秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "code1.h"
#include "code1.c"
FILE *deCpsFp;
int root;
void getChar();
int fileToBuffer();
void itoc(unsigned char key,char buffer[])
{
    for(int i = 7; i >= 0; i--){
        if(key & 1 == 0){
            buffer[i] = '0';
        }else {
            buffer[i] = '1';
        }
        key = key >> 1;
    }
    buffer[8] = '\0';

    
}
void decompress()
{
    fileToBuffer();
    getChar();

}
int fileToBuffer()
{
    codeBuffer = (char *)malloc(sizeof(char) * 500000);
    unsigned char key;
    char buffer[9];
    deCpsFp = fopen("test2.code", "r+");
    while(feof(deCpsFp) == 0){
        fscanf(deCpsFp, "%c",key);
        itoc(key,buffer);
        printf("***\n");
        strcat(codeBuffer,buffer);
        printf("&&&\n");
        memset(buffer, 0, 9);
        printf("@@@\n");
    }

}
void getChar()
{
	int i = root;
	char *p = &codeBuffer[0];
    printf("(%s)\n",codeBuffer);
	char key;
    FILE *Fp;
    Fp = fopen("test2.decode","w+");
    /*
	while(*p != '\0'){
        i = root;
		while(treeNode[i].leftChild != 0 && treeNode[i].rightChild != 0){
			if(*p == '0'){
				i = treeNode[i].leftChild;
				p++;
			}else{
				i = treeNode[i].rightChild;
				p++;
			}
		}
        key = (char)i;
        fprintf(Fp,"%c",key);
	}
    */
}

unsigned char ctoi(char buffer[])
{
    unsigned char key;
    for(int i = 0; i < 7; i++){
        key += buffer[i]*pow(2,7-i);
    } 
    return key;

}

void saveTree()
{
    compressfp = fopen(compressFile,"w+");

}

void compressChar(char buffer[], int count)
{
    unsigned char key;
    if(count != 8){
        memset((&buffer[0]) + count, 0, 8-count);
        fprintf(compressfp,"%c%c",key,-1);

    }
    key = ctoi(buffer);
    //printf("^^^^%c\n",key);
    fprintf(compressfp,"%c",key);
    
}



int spiltBuffer()
{
    char buffer[9];
    char *p = &codeBuffer[0];
    char *q = p;
    int count = 0;
    while(*p != '2'){
        p++;
        count++;
        if(count == 8){
            memcpy(buffer, q, 8);
            compressChar(buffer,8);
            //printf("$$$%d$$$\n",count);
            q = q + 8;
            count = 0;
        }
    }
    memcpy(buffer, q, count);
    compressChar(buffer,count);
}

int main(void)
{
    FILE *fp;
    fp = chooseFile(CODE);
    getWeight(fp);
    creatTree();
    printf("*******************************************************************\n");
    print();
    printf("*******************************************************************\n");
    saveTree();
    codeToBuffer(fp);
    spiltBuffer();

    //fileToBuffer();
}


