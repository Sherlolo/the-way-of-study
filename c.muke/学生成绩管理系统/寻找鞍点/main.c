#include <stdio.h>
#define N 99
void FindSaddlePoint(int a[][N], int m, int n);

int main(void)
{
    int a[N][N], i, j;
    int m, n;
    printf("Input m,n:\n");
    scanf("%d,%d",&m,&n);
    printf("Input matrix:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d",&a[i][j]);
    }
    FindSaddlePoint(a,m,n);
    return 0;
}

void FindSaddlePoint(int a[][N], int m, int n)
{
    int flag, x = a[0][0];
    int i, j, k, h = 0, l = 0;
    for(i = 0; i < m; i++)
    {
        flag = 1;
        for(j = 0; j < n; j++)
        {
            if(a[i][j] > x)
            {
                x = a[i][j];
                h = i;
                l = j;
            }
        }
        for(k = 0; k < m; k++)
        {
            if(x > a[k][l])
                flag = 0;
        }
        if(flag)
        {
            printf("a[%d][%d] is %d\n",h,l,x);
            return ;
        }
    }
    printf("No saddle point!\n" );
}


