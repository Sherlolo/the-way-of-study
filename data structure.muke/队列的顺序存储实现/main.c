#include <stdio.h>
#include <stdlib.h>
#define N 6
typedef struct lnode *Que;
struct lnode
{
    int data[N];
    int front;
    int rear;
}s;
void add(Que ptr, int x);
int del(Que ptr);
void print(Que ptr);

int main(void)
{
    Que ptr = &s;
    int i;
    ptr->front = ptr->rear = 0;
    for(i = 0; i < 6; i++)
    {
        printf("%d\n",i);
        add(ptr, i);
    }
    printf("after add\n");
    print(ptr);
    printf("after del\n");
    del(ptr);
    print(ptr);
    return 0;
}

void add(Que ptr, int x)
{
    if((ptr->rear+1)%N == ptr->front)
    {
        printf("the que is full\n");
        return;
    }
    ptr->rear = (ptr->rear+1)%N;
    ptr->data[ptr->rear] = x;
}

int del(Que ptr)
{
    if(ptr->front == ptr->rear)
    {
        printf("the que is empty\n");
        return -1;
    }
    else
    {
        ptr->front = (ptr->front+1)%N;
        return ptr->data[ptr->front];
    }
}

void print(Que ptr)
{
    int i;
    for(i = ptr->front+1; i <= ptr->rear; i++)
    {
        printf("%d ",ptr->data[i]);
    }
    putchar('\n');
}
