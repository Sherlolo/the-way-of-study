#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree *bintree;
struct tree
{
    char data;
    int tag;
    bintree right;
    bintree left;
};
typedef struct lnode *Stack;
struct lnode
{
    bintree ptr;
    Stack next;
};

void create(bintree *t);    //创建一个二叉树
void PostOrderTraversal(bintree BT);  //先序遍历的非递归算法
Stack CreateStack(void);    //创建一个堆栈
void push(Stack s, bintree t);
bintree pop(Stack s);
int Isempty(Stack s);

int main(void)
{
    bintree t;  //abd##e##cf###
    create(&t);
    PostOrderTraversal(t);
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

void PostOrderTraversal(bintree BT)  //先序遍历的非递归算法
{
    bintree t = BT;
    Stack s = CreateStack();
    while(t || !Isempty(s))
    {
        while(t)
        {
            t->tag = 0;
            push(s,t);
            t = t->left;
        }
        if(!Isempty(s))
        {
            t = pop(s);
            if(t->tag == 0)
            {
                t->tag = 1;
                push(s,t);
                t = t->right;
            }
            else
            {
                printf("%c  ",t->data);
                t = NULL;
            }
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

Stack CreateStack(void)    //创建一个堆栈
{
    Stack s = (Stack)malloc(sizeof(struct lnode));
    s->next = NULL;
    return s;
}
