#include<stdio.h>

int map1 [100][100];
int triple1[200],sum1;
int triple2[200],sum2;
int triple3[200],pos=1,sum3;

void init1()
{
	scanf("%d",&sum1);
	int i;
	for( i = 1; i <= sum1*3; i++){
		scanf("%d",&triple1[i]);
	}
}
void init2()
{
	int i;
	scanf("%d",&sum2);
	for( i = 1; i <= sum2*3; i++){
		scanf("%d",&triple2[i]);
	}
}
void sub()
{
	int count = 1;
	int temp = 1;
	int flag =0;
	int k  = 1;
	while(count + 2 <= sum2 * 3){
		flag = 0;
		temp = k;
		while(temp + 3 < sum1 * 3+2){
			if(triple1[temp] > triple2[count]){
				
				break;
			}
			if(triple1[temp] < triple2[count]){
				temp += 3;
				continue;
			}
			if(triple1[temp] == triple2[count]){
				if(triple1[temp + 1] == triple2[count + 1]){
					triple3[pos] = triple1[temp];
					triple3[pos + 1] = triple1[temp + 1];
					triple3[pos + 2] = triple1[temp + 2] - triple2[count + 2];
					pos += 3;
					flag = 1;
					break;
				}else if(triple1[temp + 1] < triple2[count + 1]){
					triple3[pos] = triple1[temp];
					triple3[pos + 1] = triple1[temp + 1];
					triple3[pos + 2] = -triple1[temp + 2];
					pos += 3;
					k = temp + 3;
					temp += 3;
				} else if(triple1[temp + 1] > triple2[count + 1]){
					triple3[pos] = triple1[temp];
					triple3[pos + 1] = triple1[temp + 1];
					triple3[pos + 2] = -triple1[temp + 2];
					pos += 3;
					k = temp + 3;
					temp += 3;
				} else temp += 3;
			}
		}
		if(flag){
			count += 3;
			continue;
		}
		triple3[pos] = triple2[count];
		triple3[pos + 1] = triple2[count + 1];
		triple3[pos + 2] = -triple2[count + 2];
		pos += 3;
		count += 3;
	}
}
void add()
{
	int count = 1;
	int temp = 1;
	int flag =0;
	int k  = 1;
	while(count + 2 <= sum2 * 3){
		flag = 0;
		temp = k;
		while(temp + 3 < sum1 * 3+2){
			if(triple1[temp] > triple2[count]){
				
				break;
			}
			if(triple1[temp] < triple2[count]){
				temp += 3;
				continue;
			}
			if(triple1[temp] == triple2[count]){
				if(triple1[temp + 1] == triple2[count + 1]){
					triple3[pos] = triple1[temp];
					triple3[pos + 1] = triple1[temp + 1];
					triple3[pos + 2] = triple1[temp + 2] + triple2[count + 2];
					pos += 3;
					flag = 1;
					break;
				}else if(triple1[temp + 1] < triple2[count + 1]){
					triple3[pos] = triple1[temp];
					triple3[pos + 1] = triple1[temp + 1];
					triple3[pos + 2] = triple1[temp + 2];
					pos += 3;
					k = temp + 3;
					temp += 3;
				} else if(triple1[temp + 1] > triple2[count + 1]){
					triple3[pos] = triple1[temp];
					triple3[pos + 1] = triple1[temp + 1];
					triple3[pos + 2] = triple1[temp + 2];
					pos += 3;
					k = temp + 3;
					temp += 3;
				} else temp += 3;
			}
		}
		if(flag){
			count += 3;
			continue;
		}
		triple3[pos] = triple2[count];
		triple3[pos + 1] = triple2[count + 1];
		triple3[pos + 2] = triple2[count + 2];
		pos += 3;
		count += 3;
	}
}
int main(void)
{
	int i,j;
	init1();
	init2();
    //sub();
	add();
	printf("%d\n", pos);
	for ( i = 1; i <= pos -1; i = i+3)
	{
		map1[triple3[i]][triple3[i+1]] =triple3[i+2] ;
		
	}
	for (i = 1; i <= 3; ++i)
	{
		for (j = 1; j <= 3; ++j)
		{
			printf("%d ", map1[i][j]);
		}
		printf("\n");
	}
}
