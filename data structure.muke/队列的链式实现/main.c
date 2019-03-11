#include <stdio.h>
#include <stdlib.h>
typedef struct node *Que;
typedef struct qnode *Queue; //不带头结点的队列
struct node
{
    int data;
    Que next;
};
struct qnode
{
    Que front;
    Que rear;
}s;
int del(Queue ptr);
void add(Queue ptr, int x);
void print(Queue ptr);

int main(void)
{
    Queue ptr = &s;
    int i;
    ptr->front = (Que)malloc(sizeof(struct node));
    ptr->front->data = 0;
    ptr->rear = ptr->front;
    for(i = 1; i < 6; i++)
    {
        add(ptr, i);
    }
    printf("after add\n");
    print(ptr);
    printf("after del\n");
    del(ptr);
    print(ptr);
    return 0;
}

int del(Queue ptr)
{
    Que temp;
    int y = -1;
    if(ptr->front == NULL)
    {
        printf("the queue is empty\n");
        return y;
    }
    temp = ptr->front;
    y = ptr->front->data;
    if(ptr->front == ptr->rear)
    {
        ptr->front = ptr->rear = NULL;
        return y;
    }
    else
    {
        ptr->front = temp->next;
        free(temp);
        return y;
    }
}

void add(Queue ptr, int x)
{
    Que temp = (Que)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = x;
    ptr->rear->next = temp;
    ptr->rear = temp;
}

void print(Queue ptr)
{
    Que temp = ptr->front;
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    putchar('\n');
}
