#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
struct Treenode
{
    char data;
    int left;
    int right;
}t1[MAX],t2[MAX];
int buildtree(struct Treenode t[]);
int judge(int x1, int x2);

int main(void)
{
    int a, b;
    a = buildtree(t1);
    b = buildtree(t2);
    if(judge(a,b))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

int buildtree(struct Treenode t[])
{
    int i, root, N, check[MAX];
    root = -1;
    char cl, cr;
    printf("please input the amout of node\n");
    scanf("%d",&N);
    if(N)
    {
        for(i = 0; i < N; i++)
            check[i] = 0;
        for(i = 0; i < N; i++)
        {
            printf("please input data cl cr\n");
            scanf(" %c %c %c",&t[i].data,&cl,&cr);
            if(cl != '-')
            {
                t[i].left = cl - '0';
                check[t[i].left] = 1;
            }
            else
                t[i].left = -1;
            if(cr != '-')
            {
                t[i].right = cr - '0';
                check[t[i].right] = 1;
            }
            else
                t[i].right = -1;
        }
        for(i = 0; i < N; i++)
            if(!check[i])
                break;
        root = i;
    }
    return root;
}

int judge(int x1, int x2)
{
    if(x1==-1 && x2==-1)
        return 1;
    if((x1==-1&&x2!=-1)||(x2==-1&&x1!=-1))
        return 0;
    if(t1[x1].data!=t2[x2].data)
       return 0;
    if(t1[x1].left==-1 && t2[x2].left==-1)
        return judge(t1[x1].right,t2[x2].right);
    if((t1[x1].left!=-1 && t2[x2].left!=-1)&&(t1[t1[x1].left].data==t2[t2[x2].left].data))
        return(judge(t1[x1].right,t2[x2].right)&&judge(t1[x1].left,t2[x2].left));
    else
        return(judge(t1[x1].right,t2[x2].left)&&judge(t1[x1].left,t2[x2].right));
}
