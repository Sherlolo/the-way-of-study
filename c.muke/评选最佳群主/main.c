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
��ʾ�����ѡ��������"Input the number of electorates:"
��ʾ�����ѡ�ˣ� "Input vote %d:"
�����ʽ:
    �����ѡ��������"%d"
    �����ѡ��������"%s"
�����ʽ��
    �����ѡ�˵�Ʊ����"%s:%d\n"
    ���Ʊ�����ĺ�ѡ��������"%s wins\n"
����ѡ�����ʾ��Ϣ��"Election results:\n"
*/
