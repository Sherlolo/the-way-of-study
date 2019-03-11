#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 3
#define N 10000
int *maxs(int a[],int k);
int main(void)
{
    int k,a[N],i;
    int *x = (int *)malloc(sizeof(int)*3);
    scanf("%d",&k);
    for(i = 0; i < k; i++)
        scanf("%d",&a[i]);
    x = maxs(a,k);
    printf("%d %d %d",*x,*(x+1),*(x+2));
    return 0;
}
int *maxs(int a[],int k)
{
    int i,j,thissum = 0,maxsum = 0;
    static int x[3];
    x[0] = maxsum;
    x[1] = a[0];
    x[2] = a[k-1];
    for(i = 0; i < k; i++)
    {
        thissum = 0;
        for(j = i; j < k; j++)
        {
            thissum += a[j];
            if(thissum > maxsum)
            {
                maxsum = thissum;
                x[1] = a[i];
                x[2] = a[j];
            }
            if((thissum==0)&&(maxsum==0))
            {
                maxsum = thissum;
                x[1] = a[i];
                x[2] = a[j];
            }
        }
    }
    x[0] = maxsum;
    return x;
}
