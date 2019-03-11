#include <stdio.h>
#include <math.h>
#define N 9
int fun(int temp,int i);    //求temp上第i位上的数字
int contrast(int x[]);      //判断数组是否两两相同
void sorts(int x[]);         //升序排列数组//判断数组是否两两相同

int main(void)
{
    int a, b, c, x, temp;         //x表示第一个数字，a,b,c分别表示x上第3、2、1位的数字
    int f[N], i, t;               //f[N]依次储存x、2x、3x上的数字
    for(a = 1; a <= 9; a++)
    {
        for(b = 0; b<=9; b++)
        {
            if(b!=a)
            {
                for(c = 0; c<=9; c++)
                {
                if(c!=b && c!=a)
                {
                    x = a*100 + b*10 + c;
                    for(i = 0; i < 9; i++)
                    {
                        t = i%3 + 1;
                        temp = (i/3+1)*x;
                        f[i] = fun(temp,t);
                    }
                    sorts(f);
                    if(contrast(f) == 1)
                    printf("%d,%d,%d\n",x,2*x,3*x);
                }
                }
            }
        }

    }
    return 0;
}

int fun(int temp,int i)
{
    int y;
    y = temp/(int)(pow(10,i-1)+0.5)%10;
    return y;
}

void sorts(int x[])
{
    int i, j, temp;
    for(i = 0; i < N - 1; i++)
    {
        for(j = 1; j < N - i; j++)
        {
            if(x[j] < x[j-1])
            {
                temp = x[j];
                x[j] = x[j-1];
                x[j-1] = temp;
            }
        }
    }
}

int contrast(int x[])
{
    int i;
    for(i = 1; i < N; i++)
    {
        if(x[i] == x[i-1])
            return -1;
    }
    return 1;
}
