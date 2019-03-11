#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print( List L );

List Merge( List L1, List L2 ); //����������������кϲ�
//���������ͷ���

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
List Read()
{
    int n;
    scanf("%d",&n);
    List L=(List)malloc(sizeof(PtrToNode));   ///����һ��ͷ���
    L->Next = NULL;        ///ͷָ��Ϊ��
    if(n)    ///��n����0ʱ
    {
        List r=L;     ///r��һ���м�����Ľڵ�
        for(int i=0;i<n;i++)
        {
            List p=(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));    ///β�巨
            r->Next = p;
            r = p;
        }
        r->Next = NULL;
    }
    return L;
}

void Print( List L )
{
   List p=L->Next;
   if(p)
   {
       List r;
       r = L;
       while(r->Next)
       {
           r = r->Next;
           printf("%d ",r->Data);
       }
   }
   else
   {
       printf("NULL");
   }
   printf("\n ");
}
List Merge( List L1, List L2 )
{
    List L,p,a,b;
    List temp;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    p = L;
    a = L1->Next;
    b = L2->Next;
    while(a && b)
    {
        if(a->Data < b->Data)
        {
            temp = (List)malloc(sizeof(struct Node));
            temp->Next = NULL;
            temp->Data = a->Data;
            p->Next = temp;
            p = p->Next;
            a = a->Next;
        }
        else if(a->Data == b->Data)
        {
            temp = (List)malloc(sizeof(struct Node));
            temp->Next = NULL;
            temp->Data = a->Data;
            p->Next = temp;
            p = p->Next;
            a = a->Next;
            b = b->Next;
        }
        else
        {
            temp = (List)malloc(sizeof(struct Node));
            temp->Next = NULL;
            temp->Data = b->Data;
            p->Next = temp;
            p = p->Next;
            b = b->Next;
        }
    }
    for( ;a;a = a->Next)
    {
        temp = (List)malloc(sizeof(struct Node));
        temp->Next = NULL;
        temp->Data = a->Data;
        p->Next = temp;
        p = p->Next;
    }
    for( ;b;b = b->Next)
    {
        temp = (List)malloc(sizeof(struct Node));
        temp->Next = NULL;
        temp->Data = b->Data;
        p->Next = temp;
        p = p->Next;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}
/*List Merge( List L1, List L2 ) �������м����temp�ĸ�д ���д���
{
    List L,p,a,b;
    L = (List)malloc(sizeof(struct Node));
    L->Next = (List)malloc(sizeof(struct Node));
    L->Next->Next = NULL;
    p = L->Next;
    a = L1->Next;
    b = L2->Next;
    while(a && b)
    {
        if(a->Data < b->Data)
        {
            p->Data = a->Data;
            p->Next = (List)malloc(sizeof(struct Node));
            p->Next->Next = NULL;
            p = p->Next;
            a = a->Next;
        }
        else if(a->Data == b->Data)
        {
            p->Data = a->Data;
            p->Next = (List)malloc(sizeof(struct Node));
            p->Next->Next = NULL;
            p = p->Next;
            a = a->Next;
            b = b->Next;
        }
        else
        {
            p->Data = b->Data;
            p->Next = (List)malloc(sizeof(struct Node));
            p->Next->Next = NULL;
            p = p->Next;
            b = b->Next;
        }
    }
    for( ;a;a = a->Next)
    {
        p->Data = a->Data;
        p->Next = (List)malloc(sizeof(struct Node));
        p->Next->Next = NULL;
        p = p->Next;
    }
    for( ;b;b = b->Next)
    {
        p->Data = L2->Data;
        p->Next = (List)malloc(sizeof(struct Node));
        p->Next->Next = NULL;
        p = p->Next;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    p = NULL;
    return L;
}*/
