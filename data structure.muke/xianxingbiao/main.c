#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40
typedef struct
{
    int date[MAX];
    int length;
}londe;
void init(londe *lists);  //��ʼ�����Ա�
void scans(londe *lists); //�����Ա�ֵ
void inserts(londe *lists,int i); //�������Ա�
void deletess(londe *lists,int i); //ɾ�����Ա�
void printfs(londe *lists);        //������Ա�
int searchs(londe *lists,int x); //����x��λ��

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
    printf("xλ����%d\n",searchs(&y,x));
    return 0;
}
void init(londe *lists)  //��ʼ�����Ա�
{
    lists -> date[0] = 1;
    lists -> length = 0;
}
void scans(londe *lists) //�����Ա�ֵ
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
void inserts(londe *lists,int i) //�����Ա��i��λ�ò���Ԫ��
{
    int n = lists->length;
    int j;
    if(n == MAX-1)
        printf("���Ա����� �޷�����\n");
    if(i<1||i>n)
        printf("����λ���д���");
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
void deletess(londe *lists,int i) //ɾ�����Ա�
{
    int n = lists->length;
    int j;
    if(i<1||i>n)
        printf("����λ���д���");
    else
    {
        for(j = i;j < n;j++)
        {
            lists->date[j] = lists->date[j+1];
        }
    }
    lists->length--;
}
int searchs(londe *lists,int x) //����x��λ��
{
    int i;
    int n = lists->length;
    for(i = 1; i < n;i++)
        if(lists->date[i]==x)
        return i;
}
void printfs(londe *lists)        //������Ա�
{
    int n = lists->length;
    int i;
    for(i = 1; i < n;i++)
    {
        printf("the %d number is %d\n",i,lists->date[i]);
    }
}
