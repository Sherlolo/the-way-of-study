#include <stdio.h>
#define N 101
#define M 99
int fun(int a[], int n);

int main(void)
{
    int a[N], i;
    for(i = 0; i < N; i++)
    {
        a[i] = i;
    }
    printf("lu zhisheng is %d\n",fun(a,N));
    return 0;
}

int fun(int a[], int n)
{
    int i = 1, j = 0, sum = 0;
    while(sum < M)
    {
        if(i == n)
            i = 1;
        if(a[i] != 0)
            j++;
        if(j!=0 && j%5==0)
        {
            a[i] = 0;
            j = 0;
            sum++;
        }
        i++;
    }
    for(i = 1; i < n; i++)
    {
        if(a[i] != 0)
            break;
    }
    return a[i];
}
