#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
void make(int a[]);     //生成四个互异随机数
void input(int b[]);    //输入
int fun_a(int a[], int b[]);
int fun_b(int a[], int b[]); //b+a的个数

int main(void)
{
    int a[N], b[N];
    int i, n, x1, x2;   //i记录猜的次数
    printf("How many times do you want guess?\n");
    scanf("%d",&n);
    make(a);
    for(i = 0; i<n && x1!=4; i++)
    {
        input(b);
        x1 = fun_a(a,b);
        x2 = fun_b(a,b) - x1;
        printf("%dA%dB\n",x1,x2);
    }
    if(x1 == 4)
        printf("Great! you guess it right\n");
    else
        printf("Sorry,you din't guess it\n");
    printf("the right number is %d%d%d%d",a[0],a[1],a[2],a[3]);
    return 0;
}

void make(int a[])
{
    srand(time(NULL));
    a[0] = rand()%10;
    do
    {
        a[1] = rand()%10;
    }while(a[0]==a[1]);
    do
    {
        a[2] = rand()%10;
    }while(a[2]==a[1] || a[2]==a[0]);
    do
    {
        a[3] = rand()%10;
    }while(a[3]==a[1] || a[3]==a[0] || a[3] == a[2]);
}

void input(int b[])
{
    int i;
    do
    {
        printf("please input the different guess\n");
        for(i = 0; i < N; i++)
        {
            scanf("%d",&b[i]);
        }
    }while(b[0]==b[1]||b[0]==b[2]||b[0]==b[3]||b[1]==b[2]||b[1]==b[3]||b[2]==b[3]);
}

int fun_a(int a[], int b[])
{
    int i, sum;
    for(i = 0, sum = 0; i < N; i++)
    {
        if(a[i] == b[i])
            sum++;
    }
    return sum;
}

int fun_b(int a[], int b[])
{
    int i, j, sum = 0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(a[i] == b[j])
                sum++;
        }
    }
    return sum;
}
