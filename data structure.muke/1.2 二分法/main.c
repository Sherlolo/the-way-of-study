#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L,X);
    printf("%d\n",P);

    return 0;
}

Position BinarySearch( List L, ElementType X )
{
    int start,ends,m = 0;
    int y = NotFound;
    start = 1;
    ends = L->Last;
    while(start <= ends)
    {
        m = start + (ends - start)/2;
        if(L->Data[m] == X)
        {
            y = m;
            break;
        }
        else if(X > L->Data[m])
        {
            start = m + 1;
        }
        else
        {
            ends = m - 1;
        }
    }
        return y;
}
List ReadInput()
{
    int i;
    List L;
    L = (struct LNode*)malloc(sizeof(struct LNode));
    scanf("%d",&L->Last);
    L->Data[0] = 0;
    for(i = 1; i <= L->Last; i++)
        scanf("%d",&L->Data[i]);
    return L;
}
