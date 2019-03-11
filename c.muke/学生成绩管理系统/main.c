#include <stdio.h>
#include <string.h>
#include <math.h>
#define P 100   //���ѧ������
#define N 6     //����Ŀ,���� Ӣ�� ��ѧ ���� ��ѧ ����
#define V 20 //������ֳ���
char *subject[N] = {"����","Ӣ��","��ѧ","����","��ѧ","����"};
typedef struct data
{
    char name[V];
    int study; //ѧ��Ϊ4λ��
    float a[N];//ѧ�Ƴɼ�
    float sum;
    float aver;
}student;
void input(student x[P], int p, int n); //��������
void count_subject(student x[P], int p, int n); //�����ѧ�Ƶ��ܷ�ƽ���ֲ����
void count_person(student x[P], int p, int n);  //����ÿ���˵��ܷ�ƽ����
void print1(student x[P], int p, int n);         //���ִܷӸߵ����������
void print2(student x[P], int p, int n);         //��ѧ�Ŵӵ͵����������
void search1(student x[P], int p, int n);       //��ѧ�Ų�ѯѧ���������俼�Գɼ�
void search2(student x[P], int p, int n);       //��������ѯѧ���������俼�Գɼ�
void countsj(student x[P], int p, int n);       //��ÿ�ſγ̷ֱ�ͳ���ĸ����������Լ���ռ�İٷֱ�
void print3(student x[P], int p, int n);       //���ѧ���ĸ�����Ϣ
//�������д ������д

int main(void)
{
    student x[P];
    int p, n, z; //p��������,n����ѧ����Ŀ z�жϹ���
    printf("������ѧ�������Ϳ�Ŀ����\n");
    scanf("%d %d",&p,&n);
    printf("1*��������                                             -1*�˳�����\n");
    printf("2*�����ѧ�Ƶ��ܷ�ƽ���ֲ����                          3*����ÿ���˵��ܷ�ƽ����\n");
    printf("4*���ִܷӸߵ����������                              5*��ѧ�Ŵӵ͵����������\n");
    printf("6*��ѧ�Ų�ѯѧ���������俼�Գɼ�                        7*��������ѯѧ���������俼�Գɼ�\n");
    printf("8*��ÿ�ſγ̷ֱ�ͳ���ĸ����������Լ���ռ�İٷֱ�      9*���ѧ���ĸ�����Ϣ\n");
    printf("************************************************************************\n");
    do
    {
        printf("��ѡ����:");
        while(scanf("%d",&z) != 1||z < -1)
        {
            printf("��������,���ٴ�����:");
            while(getchar() != '\n');
        }
        switch (z)
            {
            case 1:
                input(x,p,n);
                break;
            case 2:
                count_subject(x,p,n);
                break;
            case 3:
                count_person(x,p,n);
                break;
            case 4:
                print1(x,p,n);
                break;
            case 5:
                print2(x,p,n);
                break;
            case 6:
                search1(x,p,n);
                break;
            case 7:
                search2(x,p,n);
                break;
            case 8:
                countsj(x,p,n);
                break;
            case 9:
                print3(x,p,n);
                break;
            case -1:
                printf("������� ��ӭʹ��\n");
                break;
            default:
                printf("��������\n");
                break;
            }
            putchar('\n');
    }while(z != -1);
    return 0;
}

void input(student x[P], int p, int n)
{
    int i, j;
    for(i = 0; i < p; i++)
    {
        while(getchar() != '\n');
        printf("�������%d��ѧ��������\n",i+1);
        printf("����������:");
        gets(x[i].name);
        printf("������ѧ��:");
        while(scanf("%d",&x[i].study) != 1||x[i].study <= 0)
        {
            printf("�����ѧ�ţ����ٴ�����:");
            while(getchar() != '\n');
        }
        for(j = 0; j < n; j++)
        {
            printf("�������%d��%s�ĳɼ�:",j+1,subject[j]);
            while(scanf("%f",&x[i].a[j]) != 1||x[i].a[j] <= 0)
            {
                printf("����ĳɼ������ٴ�����:");
                while(getchar() != '\n');
            }
        }
        x[i].sum = x[i].aver = 0;
    }
    putchar('\n');
}

void count_subject(student x[P], int p, int n) //�����ѧ�Ƶ��ܷ�ƽ���ֲ����
{
    float sumsj[N] = {0};
    int i,j;
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < n; j++)
        {
            sumsj[j] += x[i].a[j];
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%s �ܷ�%f ƽ����%f\n",subject[i],sumsj[i],sumsj[i]/p);
    }
}

void count_person(student x[P], int p, int n)  //����ÿ���˵��ܷ�ƽ����
{
    int i,j;
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < n; j++)
            x[i].sum += x[i].a[j];
        x[i].aver = x[i].sum/n;
    }
}

void print1(student x[P], int p, int n)         //���ִܷӸߵ����������
{
    int i,j;
    student temp;
    for(i = 0; i < p; i++)
    {
        for(j = 1; j < p - i; j++)
        {
            if(x[j-1].sum < x[j].sum)
            {
                temp = x[j-1];
                x[j-1] = x[j];
                x[j] = temp;
            }
        }
    }
    printf("����\t����\t�ɼ�\n");
    for(i = 0; i < p; i++)
    {
        printf("%d\t%s\t%f\n",i+1,x[i].name,x[i].sum);
    }
    putchar('\n');
}

void print2(student x[P], int p, int n)         //��ѧ�Ŵӵ͵����������
{
    int i,j;
    student temp,t[p];
    for(i = 0; i < p; i++)
    {
        t[i] = x[i];
    }
    for(i = 0; i < p; i++)
    {
        for(j = 1; j < p - i; j++)
        {
            if(t[j-1].study > t[j].study)
            {
                temp = t[j-1];
                t[j-1] = t[j];
                t[j] = temp;
            }
        }
    }
    printf("ѧ��\t����\t�ɼ�\n");
    for(i = 0; i < p; i++)
    {
        printf("%d\t%s\t%f\n",t[i].study,t[i].name,t[i].sum);
    }
    putchar('\n');
}

void search1(student x[P], int p, int n)       //��ѧ�Ų�ѯѧ���������俼�Գɼ�
{
    int sear, i;
    printf("�������ѯѧ��\n");
    scanf("%d",&sear);
    for(i = 0; i < p; i++)
    {
        if(x[i].study == sear)
        {
            printf("����%s\tѧ��%d �ɼ�%f ����%d\n\n",x[i].name,x[i].study,x[i].sum,i+1);
            return 0;
        }
    }
    printf("����ѧ�� �޷���ѯ\n\n");
}

void search2(student x[P], int p, int n)       //��������ѯѧ���������俼�Գɼ�
{
    char sear[V];
    int i;
    while(getchar() != '\n');
    printf("�������ѯ����");
    gets(sear);
    for(i = 0; i < p; i++)
    {
        if(strcmp(x[i].name,sear) == 0)
        {
            printf("����%s\tѧ��%d �ɼ�%f ����%d\n\n",x[i].name,x[i].study,x[i].sum,i+1);
            return 0;
        }
    }
    printf("�������� �޷���ѯ\n\n");
}

void countsj(student x[P], int p, int n)       //��ÿ�ſγ̷ֱ�ͳ���ĸ����������Լ���ռ�İٷֱ�
{
    int t[N][4];
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 4; j++)
            t[i][j] = 0;
    }
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(x[i].a[j] >= 90)
                t[j][0]++;
            else if(x[i].a[j] >= 80)
                t[j][1]++;
            else if(x[i].a[j] >= 60)
                t[j][2]++;
            else
                t[j][3]++;
        }
    }
    printf("ѧ��\t����\t����\t����\t������\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n",subject[i],t[i][0],t[i][1],t[i][2],t[i][3]);
    }
    putchar('\n');
}

void print3(student x[P], int p, int n)      //���ѧ���ĸ�����Ϣ
{
    int i, j;
    printf("����\t����\t");
    for(i = 0; i < n; i++)
    {
        printf("%s\t",subject[i]);
    }
    printf("�ܷ�\tƽ����\tѧ��\n");
    for(i = 0; i < p; i++)
    {
        printf("%d\t%s\t",i+1,x[i].name);
        for(j = 0; j < n; j++)
        {
            printf("%.2f\t",x[i].a[j]);
        }
        printf("%.2f\t%.2f\t%d\n",x[i].sum,x[i].aver,x[i].study);
    }
}
