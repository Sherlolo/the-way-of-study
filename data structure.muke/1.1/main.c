#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000
int maxs(int a[],int k);
int main(void)
{
    int k,a[N],i;
    scanf("%d",&k);
    for(i = 0; i < k; i++)
        scanf("%d",&a[i]);
    printf("%d\n",maxs(a,k));
    return 0;
}
int maxs(int a[],int k)
{
    int i,thissum,maxsum;
    thissum = maxsum = 0;
    for(i = 0; i < k; i++)
    {
        thissum += a[i];
        if(thissum > maxsum)
            maxsum = thissum;
        if(thissum < 0)
            thissum = 0;
    }
    return maxsum;
}
