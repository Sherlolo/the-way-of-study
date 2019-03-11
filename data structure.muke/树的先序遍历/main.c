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
void PreOrederTraversal(bintree BT);    //�������

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

void PreOrederTraversal(bintree BT)    //�������
{
    if(BT)
    {
        printf("%c",BT->data);
        PreOrederTraversal(BT->left);
        PreOrederTraversal(BT->right);
    }
}
