#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree *bintree;
struct tree
{
    char data;
    bintree right;
    bintree left;
};
typedef struct lnode *Stack;
struct lnode
{
    bintree ptr;
    Stack next;
};

void create(bintree *t);    //����һ��������
void InOrderTraversal(bintree BT);  //�ǵݹ��㷨
Stack CreateStack(void);    //����һ����ջ
void push(Stack s, bintree t);
bintree pop(Stack s);
int Isempty(Stack s);

int main(void)
{
    bintree t;  //abd##e##cf###
    create(&t);
    InOrderTraversal(t);
    return 0;
}

void create(bintree *t)
{
    char ch;
    scanf(" %c",&ch);
    if(ch == '#')
    {
        *t = NULL;
    }
    else
    {
        *t = (bintree)malloc(sizeof(struct tree));
        if(!*t)
            exit (-1);
        (*t)->data = ch;
        create(&(*t)->left);
        create(&(*t)->right);
    }
}

void InOrderTraversal(bintree BT)  //��������ķǵݹ��㷨
{
    bintree t = BT;
    Stack s = CreateStack();
    while(t || !Isempty(s))
    {
        while(t)
        {
            printf("%c  ",t->data);
            push(s,t);
            t = t->left;
        }
        if(!Isempty(s))
        {
            t = pop(s);
            /*printf("%c  ",t->data); ����*/
            t = t->right;
        }
    }
}

void push(Stack s, bintree t)
{
    Stack temp = (Stack)malloc(sizeof(struct lnode));
    temp->ptr = t;
    temp->next = s->next;
    s->next = temp;
}

bintree pop(Stack s)
{
    Stack temp;
    bintree y;
    temp = s->next;
    s->next = temp->next;
    y = temp->ptr;
    free(temp);
    return y;
}

int Isempty(Stack s)
{
    if(s->next == NULL)
        return 1;
    else
        return 0;
}

Stack CreateStack(void)    //����һ����ջ
{
    Stack s = (Stack)malloc(sizeof(struct lnode));
    s->next = NULL;
    return s;
}
