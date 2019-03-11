#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
int main(void)
{
    int k,a[N],i;
    int start,ends,thissum = 0,maxsum = 0,st;
    scanf("%d",&k);
    for(i = 0; i < k; i++)
        scanf("%d",&a[i]);
    start = st = a[0];
    ends = a[k-1];
    for(i = 0; i < k; i++)
    {
        thissum += a[i];
        if(thissum >= maxsum)
        {
            if(thissum!=maxsum||(thissum==0&&maxsum==0))
            {
                maxsum = thissum;
                start = st;
                ends = a[i];
            }
        }
        else if(thissum < 0)
        {
            thissum = 0;
            st = a[i+1];
        }
    }
    printf("%d %d %d",maxsum,start,ends);
    return 0;
}
