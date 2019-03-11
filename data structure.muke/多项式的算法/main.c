#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX 101 //多项式最多项数即多项式加1
#define MAXK 1e6
clock_t start,stop;
double duration;
double fun1(int n,double a[],double x); //直接计算法
double fun2(int n,double a[],double x); //秦九韶算法
int main(void)
{
    double a[MAX],x,sum;
    a[0] = 1;
    int i,n;
    for(i = 1; i < MAX; i++)
    {
        a[i] = (double)(1.0/i);
    }
    printf("please input 项数 变量\n");
    scanf("%d%lf",&n,&x);
    printf("fun1\n");
    start = clock();
    for(i = 0; i < MAXK; i++)
    sum = fun1(n,a,x);
    stop = clock();
    duration = ((double)(stop - start))/CLK_TCK/MAXK;
    printf("the sum is %.5f\nthe tick is %.5f\nthe duration is %f",sum,(double)(stop - start),duration);
    putchar('\n');
    printf("fun2\n");
    start = clock();
    for(i = 0; i < MAXK; i++)
    sum = fun2(n,a,x);
    stop = clock();
    duration = ((double)(stop - start))/CLK_TCK/MAXK;
    printf("the sum is %.5f\nthe tick is %.5f\nthe duration is %f",sum,(double)(stop - start),duration);
    return 0;
}
double fun1(int n,double a[],double x)
{
    double sum = a[0];
    int i;
    for(i = 1; i <= n; i++)
    {
        sum+=(pow(x,i)*a[i]);
    }
    return sum;
}
double fun2(int n,double a[],double x)
{
    double p = a[n];
    int i;
    for(i = n; i >= 1; i--)
    {
        p=a[i - 1] + x*p;
    }
    return p;
}
