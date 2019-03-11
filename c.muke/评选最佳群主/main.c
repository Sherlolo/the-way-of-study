#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char *stu[3] = {"tom","jack","rose"}, temp[5];
    int n, i, j, Max = 0;
    int s[3] = {0};
    printf("Input the number of electorates:");
    scanf("%d",&n);
    while(getchar() != '\n');
    for(i = 0; i < n; i++)
    {
        printf("Input vote %d:",i+1);
        gets(temp);
        for(j = 0; j < 3; j++)
        {
            if(strcmp(temp,stu[j]) == 0)
                s[j] += 1;
        }
    }
    for(i = 0; i < 3; i++)
    {
        if(s[i] > s[Max])
            Max = i;
    }
    printf("Election results:\n");
    for(i = 0; i < 3; i++)
    {
        printf("%s:%d\n",stu[i],s[i]);
    }
    printf("%s wins\n",stu[Max]);
    return 0;
}
/*
提示输入候选人数量："Input the number of electorates:"
提示输入候选人： "Input vote %d:"
输入格式:
    输入候选人数量："%d"
    输入候选人姓名："%s"
输出格式：
    输出候选人得票数："%s:%d\n"
    输出票数最多的候选人姓名："%s wins\n"
出评选结果提示信息："Election results:\n"
*/
