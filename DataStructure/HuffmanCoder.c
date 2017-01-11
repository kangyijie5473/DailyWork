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

void itoc(unsigned char key,char buffer[])
{
    unsigned char  temp;
    temp = key;
    char ch;
    for(int i = 7; i >= 0; i--){
        if((ch = temp&1) == 0){
            buffer[i] = '0';
        }else {
            buffer[i] = '1';
        }
        key = key >> 1;
        temp = key;
    }
    buffer[8] = '\0';
}
void decompress()
{
    deCpsFp = fopen(compressFile, "r+");
    assert(deCpsFp != NULL);

    fseek(deCpsFp, -1, SEEK_END);
    fread(&zeroNum,1,1,deCpsFp);
    fseek(deCpsFp,0,SEEK_SET);

    fileToBuffer();
    getChar();
}

int fileToBuffer()
{
    codeBuffer = (char *)malloc(sizeof(char) * 500000);
    memset(codeBuffer, 0, 10);
    unsigned char key;
    char buffer[9];
    int i;
    while(1){
        if((i = fread(&key,1,1,deCpsFp)) != 1){
            break;
        }
        itoc(key,buffer);
        strcat(codeBuffer,buffer);
        memset(buffer, 0, 9);
    }
}
void getChar()
{
    int i = root;
    char *p = &codeBuffer[0];
    char key;
    FILE *Fp;
    Fp = fopen(deFile,"w+"); 

    int index = zeroNum;
    char *d = &codeBuffer[strlen(codeBuffer) - 1];
    d = d - 7 - index;
    *d = '\0';
    int temp = 0; 
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
        if(i == 255)
            break;
        key = i;
        fprintf(Fp,"%c",key);
        temp++;
    }
    fclose(Fp);

}

unsigned char ctoi(char buffer[])
{
    unsigned char key = 0;

    for(int i = 0; i <= 7; i++){
        key += (buffer[i]-'0')*pow(2,7-i);
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
    key = ctoi(buffer);
    fprintf(compressfp,"%c",key);
}

int spiltBuffer()
{
    char buffer[9];
    char *p = &codeBuffer[0];
    FILE * temp;
    temp = fopen("code","w");
    fprintf(temp,"%s",codeBuffer);
    char *q = p;
    int count = 0;
    while(*p != '\0'){
        p++;
        count++;
        if(count == 8){
            memcpy(buffer, q, 8);
            buffer[8] = '\0';
            compressChar(buffer,8);
            memset(buffer, 0, 8);
            q = q + 8;
            count = 0;
        }
    }
    memcpy(buffer, q, count);
    for(int i = count; i < 8; i++){
        buffer[i] = '0';
    }
    zeroNum = 8 - count;
    compressChar(buffer,count);

    fprintf(compressfp,"%c",zeroNum);
    fclose(compressfp);
}

int main(void)
{
    FILE *fp;char temp[123];
    fp = chooseFile();
    getWeight(fp);
    printf("\t\t\t\t读取文件成功！\n");
    creatTree();
    saveTree();
    codeToBuffer(fp);
    spiltBuffer();
    printf("\t\t\t\t编码成功！压缩文件为%s\n",compressFile);
    free(codeBuffer);
    printf("\t\t\t\t请输入要解压缩的文件\n\t\t\t\t");
    scanf("%s",temp);
    decompress();
    printf("\t\t\t\t解压缩成功! 解压后文件为%s\n",deFile);
}


