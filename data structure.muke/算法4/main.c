#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
int fun(int a[]);
int main(void)
{
    int a[N] = {1,2,3,-114,-5,-6,7,8,9,10};
    printf("th maxsum is %d",fun(a));
    return 0;
}
int fun(int a[])
{
    int i,thissum,maxsum;
    thissum = maxsum = 0;
    for(i = 0; i < N; i++)
    {
        thissum += a[i];
        if(thissum > maxsum)
            maxsum = thissum;
        if(thissum < 0)
            thissum = 0;
    }
    return maxsum;
}
