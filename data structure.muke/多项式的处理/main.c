#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lnode *poly;
struct lnode
{
    int c;
    int e;
    poly next;
};
poly polyadd(poly p1, poly p2);     //两个多项式相加
void attach(int a, int b, poly *p); //把a和b连在p后
int compare(int a, int b);          //比较a和b的值并返回
void print(poly p);
poly build(void); //多项式的建立

int main(void)
{
    poly p1, p2, padd;
    printf("please input p1\n");
    p1 = build();
    printf("plese input p2\n");
    p2 = build();
    padd = polyadd(p1,p2);
    print(padd);
    return 0;
}

poly polyadd(poly p1, poly p2)     //两个多项式相加
{
    poly front, rear, temp;
    front = (poly)malloc(sizeof(struct lnode));
    rear = front;
    while(p1 && p2)
    {
        switch(compare(p1->e, p2->e))
        {
        case 1:
            attach(p1->c, p1->e, &rear);
            p1 = p1->next;
            break;
        case -1:
            attach(p2->c, p2->e, &rear);
            p2 = p2->next;
            break;
        case 0:
            attach(p1->c+p2->c, p1->e, &rear);
            p1 = p1->next;
            p2 = p2->next;
            break;
        default:
            printf("error 1\n");
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

void attach(int a, int b, poly *p) //把a和b连在p后
{
    poly temp = (poly)malloc(sizeof(struct lnode));
    temp->c = a;
    temp->e = b;
    (*p)->next = temp;
    *p = temp;
}

int compare(int a, int b)          //比较a和b的值并返回
{
    if(a > b)
    {
        return 1;
    }
    else if(a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void print(poly p)
{
    while(p)
    {
        printf("c:%d e:%d  ",p->c,p->e);
        p = p->next;
    }
    putchar('\n');
}

poly build(void) //多项式的建立
{
    poly front, temp, rear;
    int c, e;
    c = e = 99;
    rear = (poly)malloc(sizeof(struct lnode));
    front = rear;
    rear->c = rear->e = 99;
    while(c != 0)
    {
        printf("please input c and e(input 0 to end):");
        scanf("%d %d",&c,&e);
        if(c == 0)
            break;
        temp = (poly)malloc(sizeof(struct lnode));
        temp->c = c;
        temp->e = e;
        rear->next = temp;
        rear = temp;
    }
    rear->next = NULL;
    putchar('\n');
    return front;
}
