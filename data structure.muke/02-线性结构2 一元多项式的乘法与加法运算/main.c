#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct strings *poly;
struct strings
{
    int c;
    int e;
    poly link;
};
void Attach(int c,int e,poly *prear);
poly read();
void put(poly p);
poly Add(poly p1,poly p2);
poly Mult(poly p1,poly p2);
int zero(poly p);
int main(void)
{
    poly p1,p2,pp,ps;
    p1 = read();
    p2 = read();
    pp = Mult(p1,p2);
    put(pp);
    ps = Add(p1,p2);
    put(ps);
}
int zero(poly p)
{
    int x = 1;
    while(p)
    {
        if(p->c!=0)
            x = 0;
        p = p->link;
    }
    return x;
}
void Attach(int c,int e,poly *prear)
{
    poly p;
    p = (poly)malloc(sizeof(poly));
    p->link = NULL;
    p->c = c;
    p->e = e;
    (*prear)->link = p;
    *prear = p;
}
poly read()
{
    poly P,Rear,t;
    int c,e,N;
    P = (poly)malloc(sizeof(poly));
    P->link = NULL;
    Rear = P;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    t = P;
    P = P->link;
    free(t);
    return P;
}
void put(poly p)
{
    int x = 0;
    if(!p)
    {
        printf("0 0\n");
        return;
    }
    else
    while(p)
    {
        if(!x)
            x = 1;
        else
            printf(" ");
        printf("%d %d",p->c,p->e);
        p = p->link;
    }
    printf("\n");
}
poly Add(poly p1,poly p2)
{
    if((zero(p1)+zero(p2))==2)
        return NULL;
    else if(zero(p1))
        return p2;
    else if(zero(p2))
        return p1;
    poly p,Rear,t1,t2,t;
    t1 = p1;
    t2 = p2;
    p = (poly)malloc(sizeof(poly));
    p->link = NULL;
    Rear = p;
    while(t1&&t2)
    {
        t = (poly)malloc(sizeof(poly));
        t->link = NULL;
        if(t1->e > t2->e)
        {
            t->c = t1->c;
            t->e = t1->e;
            Rear->link = t;
            Rear = Rear->link;
            t1 = t1->link;
        }
        else if(t1->e == t2->e)
        {
            if(t1->c + t2->c)
            {
            t->c = t1->c + t2->c;
            t->e = t1->e;
            Rear->link = t;
            Rear = Rear->link;
            }
            t1 = t1->link;
            t2 = t2->link;
        }
        else
        {
            t->c = t2->c;
            t->e = t2->e;
            Rear->link = t;
            Rear = Rear->link;
            t2 = t2->link;
        }
    }
    if(t1)
    {
        Rear->link = t1;
    }
    else if(t2)
    {
        Rear->link = t2;
    }
    t = p;
    p = p->link;
    free(t);
    return p;
}
poly Mult(poly p1,poly p2)
{
    if(zero(p1)||zero(p2))
        return NULL;
    poly p,Rear,t1,t2,t;
    int c,e;
    t1 = p1;
    t2 = p2;
    p = (poly)malloc(sizeof(poly));
    p->link = NULL;
    Rear = p;
    while(t2)
    {
        Attach(t1->c*t2->c,t1->e+t2->e,&Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while(t1)
    {
        t2 = p2;
        Rear = p;
        while(t2)
        {
            c = t1->c * t2->c;
            e = t1->e + t2->e;
            while(Rear->link && Rear->link->e > e)
                Rear = Rear->link;
            if(Rear->link && Rear->link->e == e)
            {
                if(Rear->link->c + c )
                {
                    Rear->link->c+=c;
                }
                else
                {
                    t = Rear->link;
                    Rear->link = Rear->link->link;
                    free(t);
                }
            }
            else
            {
                t = (poly)malloc(sizeof(poly));
                t->c = c;
                t->e = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t = p;
    p = p->link;
    free(t);
    return p;
}
