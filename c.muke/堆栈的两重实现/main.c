#include <stdio.h>
#define N 100
typedef struct snode *st;
struct snode
{
    int data[N];
    int top1;
    int top2;
}s;
void push(st ptr, int x, int tag);
int pop(st ptr, int tag);
void print(st ptr);

int main(void)
{
    st ptr = &s;
    ptr->top1 = -1;
    ptr->top2 = N;
    push(ptr,1,1);
    push(ptr,1,2);
    push(ptr,2,1);
    push(ptr,2,2);
    printf("after push is\n");
    print(ptr);
    printf("after pop is \n");
    pop(ptr,1);
    print(ptr);
    return 0;
}

void push(st ptr, int x, int tag)
{
    if(ptr->top2-ptr->top1 == 1)
    {
        printf("the stack is full\n");
        return;
    }
    else
    {
        if(tag == 1)
        {
            ptr->data[++(ptr->top1)] = x;
            return;
        }
        else
        {
            ptr->data[--(ptr->top2)] = x;
            return;
        }
    }
}
int pop(st ptr, int tag)
{
    if(tag == 1)
    {
        if(ptr->top1 == -1)
        {
            printf("the stack is empty\n");
            return -1;
        }
        else
        {
            return ptr->data[(ptr->top1)--];
        }
    }
    else
    {
        if(ptr->top1 == N)
        {
            printf("the stack is empty\n");
            return -1;
        }
        else
        {
            return ptr->data[(ptr->top2)++];
        }
    }
}

void print(st ptr)
{
    int i;
    printf("the top1 is \n");
    for(i = ptr->top1; i > -1; i--)
    {
        printf("%d ",ptr->data[i]);
    }
    printf("\nthe top2 is \n");
    for(i = ptr->top2; i < N; i++)
    {
        printf("%d ",ptr->data[i]);
    }
    putchar('\n');
}
