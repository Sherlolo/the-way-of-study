#include <stdio.h>
#define N 100
typedef struct snode *st;
struct snode
{
    int data[N];
    int top;
}s;
void push(st ptr, int x);
int pop(st ptr);
void print(st ptr);

int main(void)
{
    st ptr = &s;
    ptr->top = -1;
    push(ptr,1);
    push(ptr,2);
    print(ptr);
    printf("after\n");
    pop(ptr);
    print(ptr);
    return 0;
}

void push(st ptr, int x)
{
    if(ptr->top == N-1)
    {
        printf("the stack is full\n");
        return;
    }
    else
    {
        ptr->data[++(ptr->top)] = x;
        return;
    }
}

int pop(st ptr)
{
    if(ptr->top == -1)
    {
        printf("the stack is empty\n");
        return -1;
    }
    else
    {
        return ptr->data[(ptr->top)--];
    }
}

void print(st ptr)
{
    int i;
    for(i = ptr->top; i >= 0; i--)
    {
        printf("%d ",ptr->data[i]);
    }
}
