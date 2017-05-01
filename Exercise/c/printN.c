#include<stdio.h>
int main(void){
    int n;
    char *str[6]={"#include<stdio.h>","int main(void){","int n;","scanf(\"%d\",&n);","printf(\"%s\n\",str[n-1]);}"}
    scanf("%d",&n);
    if(n == 4) printf("char *str[6]=%s")
    printf("%s\n",str[n-1]);
}
