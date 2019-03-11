#include <stdio.h>
#include <math.h>
#include <string.h>
const int MAXN=10005;
int a[MAXN];

int main()
{
    int K,Start,Last,st;
    while(~scanf("%d",&K))
    {
        for(int i=0;i<K;i++)
            scanf("%d",&a[i]);
        bool flag=false;
        int ThisSum=0,MaxSum=0,st=a[0];
        for(int i=0;i<K;i++)
        {
            ThisSum+=a[i];
            if(ThisSum>=MaxSum)
            {
                if(ThisSum!=MaxSum||(ThisSum==0&&MaxSum==0))
                {
                    MaxSum=ThisSum;
                    Start=st;
                    Last=a[i];
                    flag=true;
                }
            }
            else if(ThisSum<0)
            {
                ThisSum=0;
                st=a[i+1];
            }
        }
        if(!flag)
            printf("0 %d %d\n", a[0],a[K-1]);
        else
            printf("%d %d %d\n", MaxSum,Start,Last);
    }
    return 0;
}
