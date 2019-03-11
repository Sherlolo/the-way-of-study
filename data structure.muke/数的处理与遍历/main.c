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
void create(bintree *t);    //创建一个二叉树
void PreOrderTraversal(bintree BT);    //先序遍历
void InOrderTraversal(bintree BT);    //中序遍历
void PostOrderTraversal(bintree BT);    //后序遍历

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

void PreOrderTraversal(bintree BT)    //先序遍历
{
    if(BT)
    {
        printf("%c",BT->data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}

void InOrderTraversal(bintree BT)    //中序遍历
{
    if(BT)
    {
        InOrderTraversal(BT->left);
        printf("%c",BT->data);
        InOrderTraversal(BT->right);
    }
}

void PostOrderTraversal(bintree BT)    //后序遍历
{
    if(BT)
    {
        PostOrderTraversal(BT->left);
        PostOrderTraversal(BT->right);
        printf("%c",BT->data);
    }
}
