/*************************************************************************
	> File Name: kmp.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年10月12日 星期三 14时41分58秒
 ************************************************************************/

#include<string.h>  
typedef struct seqstring{  
    char string[100];  
    int length;  
}seqstring;  
  
void getnext(seqstring p,int next[]){  
    int i,j;  
    next[0]=-1;//next[0]放上-1   
    i=0;//指向字符串每个字符的指针   
    j=-1;  
    while(i<p.length){//没有到达结尾的话   
            if(j==-1||p.string[i]==p.string[j]){//如果是第一个字符或遇到相同的字符   
                        i++;j++;next[i]=j;  
                    }   
            else  
                j=next[j];  
        }  
}   
  
int kmp(seqstring t,seqstring p,int next[]){  
    int i,j;  
    i=j=0;  
    while(i<t.length&&j<p.length){  
            if(j==-1||t.string[i]==p.string[j]){  
                        i++;j++;  
                    }  
            else  
                j=next[j];  
        }  
    if(j==p.length) return i-p.length;  
    else return -1;  
}   
int mykmp(char linuxVersion[], char objVersion[])
{  
    seqstring t,p;  
    int next[50];
    strcpy(t.string, linuxVersion);
      
    t.length=strlen(t.string);  
    strcpy(p.string,objVersion);  
    p.length=strlen(p.string);  
      
    getnext(p,next);  
    if(kmp(t, p, next) == -1){
        return -1;
    }
    else return 1;  
} 
