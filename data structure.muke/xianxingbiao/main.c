#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40
typedef struct
{
    int date[MAX];
    int length;
}londe;
void init(londe *lists);  //初始化线性表
void scans(londe *lists); //对线性表赋值
void inserts(londe *lists,int i); //插入线性表
void deletess(londe *lists,int i); //删除线性表
void printfs(londe *lists);        //输出线性表
int searchs(londe *lists,int x); //查找x的位置

int main(void)
{
    londe y;
    int i = 5,x = 12;
    init(&y);
    scans(&y);
    putchar('\n');
    printf("put the lists\n");
    printfs(&y);
    inserts(&y,i);
    putchar('\n');
    printf("charu put the lists\n");
    printfs(&y);
    deletess(&y,i);
    putchar('\n');
    printf("shuanchu put the lists\n");
    printfs(&y);
    putchar('\n');
    printf("x位置是%d\n",searchs(&y,x));
    return 0;
}
void init(londe *lists)  //初始化线性表
{
    lists -> date[0] = 1;
    lists -> length = 0;
}
void scans(londe *lists) //对线性表赋值
{
    int i;
    char s;
    for(i = 1;i < MAX&&s != 'q';i++)
    {
        printf("please input %d number andd input q end\n",i);
        scanf("%d",&(lists->date[i]));
        getchar();
        printf("please input the s\n");
        s = getchar();
    }
    lists->length = i;
}
void inserts(londe *lists,int i) //在线性表第i个位置插入元素
{
    int n = lists->length;
    int j;
    if(n == MAX-1)
        printf("线性表已满 无法插入\n");
    if(i<1||i>n)
        printf("输入位置有错误");
    else
    {
        for(j = n;j >= i;j--)
        {
            lists->date[j+1] = lists->date[j];
        }
    }
    printf("please input the date %d\n",i);
    scanf("%d",&(lists->date[i]));
    lists->length++;
}
void deletess(londe *lists,int i) //删除线性表
{
    int n = lists->length;
    int j;
    if(i<1||i>n)
        printf("输入位置有错误");
    else
    {
        for(j = i;j < n;j++)
        {
            lists->date[j] = lists->date[j+1];
        }
    }
    lists->length--;
}
int searchs(londe *lists,int x) //查找x的位置
{
    int i;
    int n = lists->length;
    for(i = 1; i < n;i++)
        if(lists->date[i]==x)
        return i;
}
void printfs(londe *lists)        //输出线性表
{
    int n = lists->length;
    int i;
    for(i = 1; i < n;i++)
    {
        printf("the %d number is %d\n",i,lists->date[i]);
    }
}
