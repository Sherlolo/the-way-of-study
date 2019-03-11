#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAXN 10 //多项式最大项数
#define MAXK 1e7
clock_t start, stop;
double dura;
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main(void)
{
    int i;
    double a[MAXN];
    for(i = 0; i < MAXN; i++)
    {
        a[i] = (double)i;
    }
    start = clock();
    for(i = 0; i < MAXK; i++)
        f1(MAXN - 1, a, 1.1);
    stop = clock();
    dura = ((double)(stop - start))/CLK_TCK;
    printf("tick1 = %f\n"
           "dura = %6.2e\n",(double)(stop - start),dura);
    start = clock();
    for(i = 0; i < MAXK; i++)
        f2(MAXN - 1, a, 1.1);
    stop = clock();
    dura = ((double)(stop - start))/CLK_TCK;
    printf("tick1 = %f\n"
           "dura = %6.2e\n",(double)(stop - start),dura);
    return 0;
}

double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for(i = 1; i <= n; i++)
    {
        p += (a[i] * pow(x,i));
    }
    return p;
}

double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for(i = n; i > 0; i--)
    {
        p = a[i-1] + x*p;
    }
    return p;
}
