#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct lnode *que;
struct lnode
{
    int c;
    int e;
    que next;
};
void attach(int a, int b, que *rear);//连接节点
void print(que x); //输出多项式
que add(que p1, que p2); //多项式加法
que build(void); //多项式的建立
int Compare(int a, int b);

int main(void)
{
    que p, p1, p2;
    printf("please input p1\n");
    p1 = build();
    printf("please input p2\n");
    p2 = build();
    p = add(p1, p2);
    printf("the p is \n");
    print(p);
    return 0;
}

void attach(int a, int b, que *rear)//连接节点
{
     que temp;
     temp = (que)malloc(sizeof(struct lnode));
     temp->c = a;
     temp->e = b;
     temp->next = NULL;
     (*rear)->next = temp;
     *rear = (*rear)->next;
}

void print(que x) //输出多项式
{
    int i = 1;
    que temp = x;
    while(temp)
    {
        printf("第%d项 c:%d e:%d\n",i,temp->c,temp->e);
        temp = temp->next;
        i++;
    }
}

que add(que p1, que p2) //多项式加法
{
    que front, temp, rear;
    int sum;
    rear = (que)malloc(sizeof(struct lnode));
    front = rear;
    while(p1 && p2)
    {
        printf("compare is %d",Compare(p1->e, p2->e));
        switch(Compare(p1->e, p2->e))
        {
        case -1:
            attach(p1->c, p1->e, &rear);
            p1 = p1->next;
            break;
        case 1:
            attach(p2->c, p2->e, &rear);
            p2 = p2->next;
            break;
        case 0:
            sum = p1->c + p2->c;
            if(sum)
            {
                attach(sum, p1->e, &rear);
            }
            p1 = p1->next;
            p2 = p2->next;
            break;
        }
    }
    for( ; p1; p1 = p1->next) attach(p1->c, p1->e, &rear);
    for( ; p2; p2 = p2->next) attach(p2->c, p2->e, &rear);
    rear->next = NULL;
    temp = front;
    front = front->next;
    free(temp);
    return front;
}
que build(void) //多项式的建立
{
    que front, temp, rear;
    int c, e;
    c = e = 1;
    rear = (que)malloc(sizeof(struct lnode));
    front = rear;
    rear->c = rear->e = 1;
    while(c != 0)
    {
        printf("please input c and e(input 0 to end):");
        scanf("%d %d",&c,&e);
        if(c == 0)
            break;
        temp = (que)malloc(sizeof(struct lnode));
        temp->c = c;
        temp->e = e;
        rear->next = temp;
        rear = temp;
    }
    rear->next = NULL;
    return front;
}

int Compare(int a, int b)
{
    return a==b?0:(a>b?1:-1);
}
