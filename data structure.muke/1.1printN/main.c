#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print1(int n); //“ª∞„for—≠ª∑
void print2(int n); //µ›πÈ
int main(void)
{
    int n,x;
    printf("please input n,x\n");
    scanf("%d,%d",&n,&x);
    if(x==1)
        print1(n);
    else
        print2(n);
    return 0;
}
void print1(int n)
{
    int i;
    for(i = 1; i <= n; i++)
        printf("%d\n",i);
}
void print2(int n)
{
    if
        (n)
    {
        print2(n-1);
        printf("%d\n",n);
    }
}
