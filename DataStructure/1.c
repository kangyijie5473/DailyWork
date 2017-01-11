#include<stdio.h>
#include<math.h>
void itoc( char key,char buffer[]);
unsigned char ctoi(char buffer[])
{
    unsigned  char key;
    for(int i = 0; i <= 7; i++){
        key += (buffer[i] - '0')*pow(2,7-i);
    } 
    return key;

}

int main(void)
{
    char buffer[9] = {'0','1','1','0','0','0','0','1'};
    unsigned char key;
    key = ctoi(buffer);
    printf("%c\n",key);

}
void itoc( char key,char buffer[])
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
