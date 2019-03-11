#include <stdio.h>
#define N 100
void Seperate(int a[], int n); //数组a[]存放用户输入的n个整数

int main(void)
{
    int a[N], n;
    int i;
    printf("Input n:");
    scanf("%d",&n);
    printf("Input numbers:");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    Seperate(a,n);
    return 0;
}

void Seperate(int a[], int n)
{
    int i, temp = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i]%2 != 0)
        {
            if(temp == 0)
            {
                printf("%d",a[i]);
                temp = -1;
            }
            else
                printf(",%d",a[i]);
        }
    }
    putchar('\n');
    temp = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i]%2 == 0)
        {
            if(temp == 0)
            {
                printf("%d",a[i]);
                temp = -1;
            }
            else
                printf(",%d",a[i]);
        }
    }
    putchar('\n');
}
