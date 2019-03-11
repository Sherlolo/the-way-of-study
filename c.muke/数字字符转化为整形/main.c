#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 8
int Myatoi(const char str[]);

int main(void)
{
    char str[N];
    printf("Input a string:");
    scanf("%7s",str);
    printf("%d",Myatoi(str));
    return 0;
}

int Myatoi(const char str[])
{
    int i = 0, sum = 0, y[N];
    int n = 0;
    memset(y, -1, sizeof(y));
    while(str[i] != '\0')
    {
        if(str[i]>='0' && str[i]<='9')
        {
            y[n] = str[i] - '0';
            n++;
        }
        i++;
    }
    n--;
    for(i = 0; y[i] != -1; i++,n--)
    {
        sum += y[i] * (int)(pow(10,n)+0.5);
    }
    return sum;
}
