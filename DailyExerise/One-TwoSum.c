/*************************************************************************
	> File Name: One-TwoSum.c
	> Author: Jack Kang
	> Mail: kangyijie@xiyoulinx.org
	> Created Time: 2016年11月25日 星期五 20时58分23秒
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target) {
    int *result;
    result = (int *)malloc(sizeof(int)*2);
    for(int i = 0; i < numsSize; i++){    
        for(int j = 0; j < numsSize; j++){
            if(i == j){
                continue;   
            }
            if(nums[i] + nums[j] == target){   
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
}
int main(void)
{
    int a[3] = {3,2,4};
    int *p;
    p = twoSum(a, 3, 6);
    printf("%d %d\n",p[0],p[1]);
}
