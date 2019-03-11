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
void create(bintree *t);    //����һ��������
void PreOrderTraversal(bintree BT);    //�������
void InOrderTraversal(bintree BT);    //�������
void PostOrderTraversal(bintree BT);    //�������

int main(void)
{
    bintree t;//abd##e##cf###
    create(&t);
    printf("preorder  ");
    PreOrderTraversal(t);
    printf("\ninorder  ");
    InOrderTraversal(t);
    printf("\npostorder  ");
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

void PreOrderTraversal(bintree BT)    //�������
{
    if(BT)
    {
        printf("%c",BT->data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}

void InOrderTraversal(bintree BT)    //�������
{
    if(BT)
    {
        InOrderTraversal(BT->left);
        printf("%c",BT->data);
        InOrderTraversal(BT->right);
    }
}

void PostOrderTraversal(bintree BT)    //�������
{
    if(BT)
    {
        PostOrderTraversal(BT->left);
        PostOrderTraversal(BT->right);
        printf("%c",BT->data);
    }
}
