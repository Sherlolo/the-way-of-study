#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treenode *tree;
struct treenode
{
    int v;
    tree left, right;
    int flag;
};
tree maketree(int n);   //建立有N个结点的树
tree newnode(int v);    //建立一个值为v的结点
tree inserts(tree t, int v);  //在树中插入一个v值
int check(tree t, int v);
int judge(tree t, int n);
void reset(tree t);     //flag置位
void freetree(tree t);  //释放t的空间

int main(void)
{
    int N, L, i;
    tree T;
    printf("please input node N and test node L\n");
    scanf("%d",&N);
    while(N)
    {
        scanf("%d",&L);
        T = maketree(N);
        for(i = 0; i < L; i++)
        {
            if(judge(T,N))
                printf("Yes\n");
            else
                printf("No\n");
            reset(T);
        }
        freetree(T);
        printf("please input node N and test node L\n");
        scanf("%d",&N);
    }
    return 0;
}

tree maketree(int n)   //建立有N个结点的树
{
    tree t;
    int i, v;
    scanf("%d",&v);
    t = newnode(v);
    for(i = 1; i < n; i++)
    {
        scanf("%d",&v);
        t = inserts(t,v);
    }
    return t;
}

tree newnode(int v)    //建立一个值为v的结点
{
    tree t = (tree)malloc(sizeof(struct treenode));
    t->v = v;
    t->right = t->left = NULL;
    t->flag = 0;
    return t;
}

tree inserts(tree t, int v)  //在树中插入一个v值
{
    if(!t)
        t = newnode(v);
    else
    {
        if(v > t->v)
            t->right = inserts(t->right,v);
        else if(v < t->v)
            t->left = inserts(t->left,v);
        /*相等不做操作*/
    }
    return t;
}

int check(tree t, int v)
{
    if(t->flag)
    {
        if(v < t->v)
            return check(t->left,v);
        else if(v > t->v)
            return check(t->right,v);
        else
            return 0;
    }
    else
    {
        if(v == t->v)
        {
            t->flag = 1;
            return 1;
        }
        else
            return 0;
    }
}

int judge(tree t, int n)
{
    int i, v, flag = 0;
    scanf("%d",&v);
    if(v != t->v)
        flag = 1;
    else
        t->flag = 1;
    for(i = 1; i < n; i++)
    {
        scanf("%d",&v);
        if((!flag)&&(!check(t,v)))
            flag = 1;
    }
    if(flag)
        return 0;
    else
        return 1;
}

void reset(tree t)
{
    if(t->left)
        reset(t->left);
    if(t->right)
        reset(t->right);
    t->flag = 0;
}

void freetree(tree t)
{
    if(t->left)
        freetree(t->left);
    if(t->right)
        freetree(t->right);
    free(t);
}
