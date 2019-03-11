#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
typedef struct winners

{

    char name[20];

    int finalScore;

    int classScore;

    char work;

    char west;

    int paper;

    int scholarship;

} WIN;
void Addup(WIN stu[], int n);       //��ֵ
void Findship(WIN *pt); //�������ѧ��

int main(void)
{
    WIN stu[N];
    int n, i, t = 0;
    printf("Input n:");
    scanf("%d",&n);
    Addup(stu,n);
    for(i = 0; i < n; i++)
    {
        if(stu[i].scholarship > stu[t].scholarship)
            t = i;
    }
    printf("%s get the highest scholarship %d\n",stu[t].name,stu[t].scholarship);
    return 0;
}

void Addup(WIN stu[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Input name:");
        scanf("%s",stu[i].name);
        printf("Input final score:");
        scanf("%d",&stu[i].finalScore);
        printf("Input class score:");
        scanf("%d",&stu[i].classScore);
        printf("Class cadre or not?(Y/N):");
        scanf(" %c",&stu[i].work);
        printf("Students from the West or not?(Y/N):");
        scanf(" %c",&stu[i].west);
        printf("Input the number of published papers:");
        scanf("%d",&stu[i].paper);
        Findship(&stu[i]);
        printf("name:%s,scholarship:%d\n",stu[i].name,stu[i].scholarship);
    }
}

void Findship(WIN *pt)
{
    int sum = 0;
    if(pt->finalScore>80 && pt->paper>=1)
        sum += 8000;
    if(pt->finalScore>85 && pt->classScore>80)
        sum += 4000;
    if(pt->finalScore>90)
        sum += 2000;
    if(pt->finalScore>85 && pt->west=='Y')
        sum += 1000;
    if(pt->classScore>80 && pt->work=='Y')
        sum += 850;
    pt->scholarship = sum;
}
/*
����ѧ��������ʾ��"Input n:"
����ѧ��������ʾ��"Input name:"
����ѧ����ĩƽ���ɼ���ʾ��"Input final score:"
����ѧ���༶����ɼ���ʾ��"Input class score:"
�����Ƿ�Ϊѧ���ɲ���ʾ��"Class cadre or not?(Y/N):"
�����Ƿ�Ϊ����ѧ����ʾ��"Students from the West or not?(Y/N):"
���뷢������������ʾ��"Input the number of published papers:"
�����ʽ��
    ����ѧ��������"%d"
    ����ѧ��������"%s"
    ����ѧ���ɼ���"%d"
    �����Ƿ�Ϊѧ���ɲ���" %c" ��ע�⣺%cǰ����һ���ո�
    �����Ƿ�Ϊ����ѧ����" %c" ��ע�⣺%cǰ����һ���ո�
    ���뷢������������ "%d"
�����ʽ
     ���ѧ����õĽ�ѧ��  "name:%s,scholarship:%d\n"
     �����ý�ѧ��������ߵ�ѧ����"%s get the highest scholarship %d\n"
*/
