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
void PreOrederTraversal(bintree BT);    //先序遍历

int main(void)
{
    bintree t;
    create(&t);
    PreOrederTraversal(t);
    return 0;
}

void create(bintree *t)
{
    char ch;
    printf("please input ch(# to end)\n");
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

void PreOrederTraversal(bintree BT)    //先序遍历
{
    if(BT)
    {
        printf("%c",BT->data);
        PreOrederTraversal(BT->left);
        PreOrederTraversal(BT->right);
    }
}
