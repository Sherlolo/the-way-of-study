#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int guess,magic,n,counter;//n猜的次数 counter计数器
    char c;//panduan
    do
    {
    counter = 0;
    printf("please input the the number 'n' of guess number\n");
    while(scanf("%d",&n)!=1||n<1)
    {
        printf("false input,please input n again\n");
        fflush(stdin);//清理输入缓存
    }
    srand(time(NULL));
    magic = rand()%100+1;
    do
    {
        printf("please input the guess number\n");
        while(scanf("%d",&guess)!=1||guess<1)
        {
            printf("false input,please input guess again\n");
            fflush(stdin);//清理输入缓存
        }
        if(magic < guess)
            printf("false,guess is too big\n");
        else if(magic > guess)
            printf("false,guess is too small\n");
        else
            printf("right,the magic is %d\n",guess);
        counter++;
    }while(guess != magic&&counter < n);
    if(guess != magic)
        printf("sorry,you can't guess the number\n");
    putchar('\n');
    printf("if you want guess again,printf Y/y\n");
    scanf(" %c",&c);
    }while(c == 'Y'||c == 'y');
    printf("over! thanks for your entering\n");
}
