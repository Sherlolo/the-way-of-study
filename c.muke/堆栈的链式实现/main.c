#include <stdio.h>
#include <stdlib.h>
typedef struct nlode *Stack;
struct nlode
{
    int data;
    Stack next;
}s;
void push(Stack str, int x);
int pop(Stack str);
void print(Stack str);

int main(void)
{
    Stack rear, temp, str = &s;
    int i;
    str->next = NULL;
    for(i = 0; i < 3; i++)
    {
        temp = (Stack)malloc(sizeof(struct nlode));
        temp->data = i;
        temp->next = str->next;
        str->next = temp;
    }
    push(str,5);
    printf("after push\n");
    print(str);
    pop(str);
    printf("after pop\n");
    print(str);
    return 0;
}

void push(Stack str, int x)
{
    Stack temp;
    temp = (Stack)malloc(sizeof(struct nlode));
    temp->data = x;
    temp->next = str->next;
    str->next = temp;
}

int pop(Stack str)
{
    Stack temp;
    int del;
    if(str->next == NULL)
    {
        printf("the stack is empty\n");
        return -1;
    }
    else
    {
        temp = str->next;
        del = temp->data;
        str->next = temp->next;
        free(temp);
        return del;
    }
}

void print(Stack str)
{
    Stack t = str->next;
    while(t)
    {
        printf("%d ",t->data);
        t = t->next;
    }
    putchar('\n');
}
