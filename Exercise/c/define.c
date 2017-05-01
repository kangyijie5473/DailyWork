#include<stdio.h> 
int main(int argc, char **argv)
{
    int x1;
    short *x2 = (short *)&x1;
    char *x3 = (char *)&x1;
    printf("%d***\n",sizeof(short));
    x1 = 0;
    *x2 = -1;
    printf("x""1"":" "%x%d\n",x1,sizeof(x1));
    printf("x""2"":" "%x%d\n",*x2,sizeof(*x2));
    printf("x""3"":" "%x%d\n",*x3,sizeof(*x3));
}
