#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct avlnode *avltree;
struct avlnode
{
    char data;
    avltree left;
    avltree right;
    int height;
};
int Max(int a, int b);
avltree singleftrotation(avltree a);    //����ת
avltree doubleleftright(avltree a);     //������ת
avltree inserts(avltree t, char x);     //��x���뵽��t�У����ز�������

int main(void)
{

    return 0;
}

int Max(int a, int b)
{
    return a>b?a:b;
}

avltree singleftrotation(avltree a)    //����ת
{
    avltree b = a->left;
    a->left = b->right;
    b->right = a;
    a->height = Max(getheight(a->left),getheight(a->right));
    b->height = Max(getheight(b->left),a->height) + 1;
    return b;
}

avltree doubleleftright(avltree a)     //������ת
{
   a->left = singlerightrotation(a->left);
   rerurn singleftrotation(a);
}

avltree inserts(avltree t, char x)     //��x���뵽��t�У����ز�������
{
    if(!t)
    {
        t = (avltree)malloc(sizeof(struct avlnode));
        t->data = x;
        t->height = 0;
        t->left = t->right = NULL;
    }
    else if(x < t->data)
    {
        t->left = inserts(t->left, x);
        if(getheight(t->left)-getheight(t->right)==2)
            if(x < t->left->data)
                t = singleftrotation(t);
            else
                t = doubleleftright(t);
    }
    else if(x > t->data)
    {
        t->right = inserts(t->right, x);
        if(getheight(t->left)-getheight(t->right)==-2)
            if(x > t->right->data)
                t = singrightrotation(t);
            else
                t = doublrightrotation(t);
    }
    t->height = Max(getheight(t->left),getheight(t->right))+1;
    return t
}
