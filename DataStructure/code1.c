/*************************************************************************
	> File Name: code1.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinux.org
	> Created Time: 2016年12月27日 星期二 09时11分23秒
 ************************************************************************/
int creatTree()
{
	for(int i = MAXLEN; i < MAXLEN+effectiveChar-1; i++){
		int node1,node2;
		findMinWeight(i-1, &node1, &node2);
		treeNode[i].weight = treeNode[node1].weight + treeNode[node2].weight;
		treeNode[i].leftChild = node1;
		treeNode[i].rightChild = node2;
		treeNode[node1].parent = i; 
		treeNode[node2].parent = i;		
	}
    root = MAXLEN+effectiveChar-2;
    return TRUE;
}
void print()
{
    for(int i = 0; i < MAXLEN*2-1; i++){
        printf("NO.%d %c weight%f leftChild%d rightChild%d parent %d \n",
               i,i,treeNode[i].weight,treeNode[i].leftChild,
               treeNode[i].rightChild, treeNode[i].parent);
    }
}
void getCode(unsigned char key, char huffmanCode[])
{
    int pos = 0;
    int  temp;
    int i = key;
    assert(treeNode[i].parent != 0);
    while(treeNode[i].parent != 0){
        temp = treeNode[i].parent;
        if(treeNode[temp].leftChild == i){
            huffmanCode[pos++] = '0';
        }else{
            huffmanCode[pos++] = '1';
        }
        i = temp;
    }
    huffmanCode[pos] = '\0';
    reverseCode(huffmanCode,pos-1);
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

FILE *chooseFile()
{
    static FILE *fp;
    char buffer[MAXLEN];
    char *key;
    system("clear");
    printf("\n\n\n\n\t\t\t\t请输入你想要压缩的文件\n\t\t\t\t");
    key = fgets(buffer, MAXLEN-1, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcat(deFile, buffer);
    strcat(deFile, ".decode");
    strcat(compressFile, buffer);
    strcat(compressFile, ".code");
    fp = fopen(buffer, "r+");
    assert(fp != NULL);
    return fp;
}

int getWeight(FILE *fp)
{
    float count = 0;
    unsigned char temp;

    while(feof(fp) == 0){
        temp = fgetc(fp);
        count += 1;
        treeNode[temp].weight += 1;
    }
    for(int i = 0; i < MAXLEN; i++){
        treeNode[i].weight = treeNode[i].weight/count;
        fileWeight[i] = (unsigned char)treeNode[i].weight*256;
        if(treeNode[i].weight != 0)
            effectiveChar++;
    }
    assert(feof(fp) != 0); 
    return TRUE;
}
void codeToBuffer(FILE *fp)
{
    char huffmanCode[20];
    unsigned char temp ;
    codeBuffer = (char *)malloc(sizeof(char)*500000);
    fseek(fp, 0, SEEK_SET);
    assert(feof(fp) == 0); 
    while(feof(fp) == 0){
        temp = fgetc(fp);
        getCode(temp,huffmanCode);
        strcat(codeBuffer,huffmanCode);
        memset(huffmanCode, 0, 20);
    }

}
void findMinWeight(int n, int *node1, int  *node2)
{
    float temp = 1.0;	
	for(int i = n; i >= 1; i--){
		if(treeNode[i].parent == 0 && 
		   treeNode[i].weight <= temp &&
           treeNode[i].weight != 0){
			*node1 = i;
			temp = treeNode[i].weight;
		}
	}
	temp = 1.0;
	for(int i = n; i >= 1; i--){
		if(treeNode[i].parent == 0 && 
		   i != *node1 &&
		   treeNode[i].weight <= temp &&
           treeNode[i].weight != 0){
			*node2 = i;
			temp = treeNode[i].weight;
		}
	}
}
