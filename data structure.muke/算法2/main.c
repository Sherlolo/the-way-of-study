#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
int maxsum(int a[]);
int main(void)
{
    int a[N] = {-1,2,3,4,5,6,7,-888,9,10};
    printf("the maxsum is %d\n",maxsum(a));
    return 0;
}
int maxsum(int a[])
{
    int maxsum = a[0],thissum;
    int i,j;
    for(i = 0; i < N;i++)
    {
        thissum = 0;
        for(j = i; j < N; j++)
        {
            thissum += a[j];
            if(thissum > maxsum)
                maxsum = thissum;
        }
    }
    return maxsum;
}
