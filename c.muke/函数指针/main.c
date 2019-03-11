#include <stdio.h>
#include <math.h>
#include <time.h>
#define N 1e5
clock_t start, stop;
float integre(float (*f)(float), float a, float b);
float f1(float x);
float f2(float x);

int main(void)
{
    float x1, x2, y;
    int i, x;
    printf("please input x1 x2\n");
    scanf("%f %f",&x1,&x2);
    printf("please choose f1 or f2\n");
    scanf("%d",&x);
    if(x == 1)
    {
        start = clock();
        for(i = 0; i < N; i++)
        {
            y = integre(f1, x1, x2);
        }
        stop = clock();
        printf("time is %f, y is %f,CLKTCK is %f\n",((double)(stop - start))/CLK_TCK,y,CLK_TCK);
    }
    else if(x == 2)
    {
        start = clock();
        for(i = 0; i < N; i++)
        {
            y = integre(f2, x1, x2);
        }
        stop = clock();
        printf("time is %f, y is %f,CLKTCK is %d\n",((double)(stop - start))/CLK_TCK,CLK_TCK);
    }
    else
    {
        printf("error input\n");
    }
    return 0;
}

float integre(float (*f)(float), float a, float b)
{
    float s, h;
    int n = 100, i;
    s = ((*f)(a)+(*f)(b)) / 2;
    h = (b - a) / n;
    for(i = 1; i < n; i++)
    {
        s += (*f)(a + i* h);
    }
    return s * h;
}

float f1(float x)
{
    return 1 + x * x;
}

float f2(float x)
{
    return x * x;
}
