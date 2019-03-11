#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
void fun_cha(int s[],int n);
void sprint(int s[],int n);
void printf4(int s[],int n);
void cha3(int s[],int n);
int longs(int s[]);//计算长度
int main(void)
{
    int s[N];
    int i,n = 10;
    for(i = 0; i < n; i++)
    {
        printf("please input a number \n");
        scanf("%d",&s[i]);
    }
    printf("cha ru 12345\n");
    fun_cha(s,n);
    n = longs(s);
    printf("%d\n",n);
    sprint(s,n);
    putchar('\n');
    printf4(s,n);
    putchar('\n');
    cha3(s,n);
    n = longs(s);
    printf("\n");
    sprint(s,n);
    return 0;
}
int longs(int s[])//计算长度
{
    int i;
    i = sizeof(s)/sizeof(int);
    return i;
}
void fun_cha(int s[],int n) //头插法插入12345
{
    int i,j;
    int t[5] = {1,2,3,4,5};
    int x = 5;
    for(i = 0; i < x; i++)
    {
        for(j = n-1; j >= 0; j--)
        {
            s[j+1] = s[j];
        }
        s[++j] = t[i];
        n++;
    }
}
void sprint(int s[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d\t",s[i]);
    }
}
void printf4(int s[],int n)
{
    printf("the 4th is\n");
    printf("%d",s[4]);
}
void cha3(int s[],int n)
{
    int i;
    for(i = n-1;i >= 2; i--)
        s[i+1] = s[i];
    printf("please input 3th\n");
    scanf("%d",&s[2]);
}
