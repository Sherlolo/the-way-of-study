#include <stdio.h>
#include <string.h>
#include <math.h>
#define P 100   //最多学生个数
#define N 6     //最多科目,语文 英语 数学 物理 化学 生物
#define V 20 //最大名字长度
char *subject[N] = {"语文","英语","数学","物理","化学","生物"};
typedef struct data
{
    char name[V];
    int study; //学号为4位数
    float a[N];//学科成绩
    float sum;
    float aver;
}student;
void input(student x[P], int p, int n); //输入数据
void count_subject(student x[P], int p, int n); //计算各学科的总分平均分并输出
void count_person(student x[P], int p, int n);  //计算每个人的总分平均分
void print1(student x[P], int p, int n);         //按总分从高到低排序并输出
void print2(student x[P], int p, int n);         //按学号从低到高排序并输出
void search1(student x[P], int p, int n);       //按学号查询学生排名及其考试成绩
void search2(student x[P], int p, int n);       //按姓名查询学生排名及其考试成绩
void countsj(student x[P], int p, int n);       //对每门课程分别统计四个类别的人数以及所占的百分比
void print3(student x[P], int p, int n);       //输出学生的各个信息
//主程序编写 防御编写

int main(void)
{
    student x[P];
    int p, n, z; //p代表人数,n代表学科数目 z判断功能
    printf("请输入学生个数和科目个数\n");
    scanf("%d %d",&p,&n);
    printf("1*输入数据                                             -1*退出程序\n");
    printf("2*计算各学科的总分平均分并输出                          3*计算每个人的总分平均分\n");
    printf("4*按总分从高到低排序并输出                              5*按学号从低到高排序并输出\n");
    printf("6*按学号查询学生排名及其考试成绩                        7*按姓名查询学生排名及其考试成绩\n");
    printf("8*对每门课程分别统计四个类别的人数以及所占的百分比      9*输出学生的各个信息\n");
    printf("************************************************************************\n");
    do
    {
        printf("请选择功能:");
        while(scanf("%d",&z) != 1||z < -1)
        {
            printf("错误输入,请再次输入:");
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
                printf("程序结束 欢迎使用\n");
                break;
            default:
                printf("错误输入\n");
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
        printf("请输入第%d个学生的数据\n",i+1);
        printf("请输入姓名:");
        gets(x[i].name);
        printf("请输入学号:");
        while(scanf("%d",&x[i].study) != 1||x[i].study <= 0)
        {
            printf("错误的学号，请再次输入:");
            while(getchar() != '\n');
        }
        for(j = 0; j < n; j++)
        {
            printf("请输入第%d科%s的成绩:",j+1,subject[j]);
            while(scanf("%f",&x[i].a[j]) != 1||x[i].a[j] <= 0)
            {
                printf("错误的成绩，请再次输入:");
                while(getchar() != '\n');
            }
        }
        x[i].sum = x[i].aver = 0;
    }
    putchar('\n');
}

void count_subject(student x[P], int p, int n) //计算各学科的总分平均分并输出
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
        printf("%s 总分%f 平均分%f\n",subject[i],sumsj[i],sumsj[i]/p);
    }
}

void count_person(student x[P], int p, int n)  //计算每个人的总分平均分
{
    int i,j;
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < n; j++)
            x[i].sum += x[i].a[j];
        x[i].aver = x[i].sum/n;
    }
}

void print1(student x[P], int p, int n)         //按总分从高到低排序并输出
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
    printf("名次\t姓名\t成绩\n");
    for(i = 0; i < p; i++)
    {
        printf("%d\t%s\t%f\n",i+1,x[i].name,x[i].sum);
    }
    putchar('\n');
}

void print2(student x[P], int p, int n)         //按学号从低到高排序并输出
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
    printf("学号\t姓名\t成绩\n");
    for(i = 0; i < p; i++)
    {
        printf("%d\t%s\t%f\n",t[i].study,t[i].name,t[i].sum);
    }
    putchar('\n');
}

void search1(student x[P], int p, int n)       //按学号查询学生排名及其考试成绩
{
    int sear, i;
    printf("请输入查询学号\n");
    scanf("%d",&sear);
    for(i = 0; i < p; i++)
    {
        if(x[i].study == sear)
        {
            printf("姓名%s\t学号%d 成绩%f 排名%d\n\n",x[i].name,x[i].study,x[i].sum,i+1);
            return 0;
        }
    }
    printf("错误学号 无法查询\n\n");
}

void search2(student x[P], int p, int n)       //按姓名查询学生排名及其考试成绩
{
    char sear[V];
    int i;
    while(getchar() != '\n');
    printf("请输入查询姓名");
    gets(sear);
    for(i = 0; i < p; i++)
    {
        if(strcmp(x[i].name,sear) == 0)
        {
            printf("姓名%s\t学号%d 成绩%f 排名%d\n\n",x[i].name,x[i].study,x[i].sum,i+1);
            return 0;
        }
    }
    printf("错误姓名 无法查询\n\n");
}

void countsj(student x[P], int p, int n)       //对每门课程分别统计四个类别的人数以及所占的百分比
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
    printf("学科\t优秀\t良好\t及格\t不及格\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n",subject[i],t[i][0],t[i][1],t[i][2],t[i][3]);
    }
    putchar('\n');
}

void print3(student x[P], int p, int n)      //输出学生的各个信息
{
    int i, j;
    printf("排名\t姓名\t");
    for(i = 0; i < n; i++)
    {
        printf("%s\t",subject[i]);
    }
    printf("总分\t平均分\t学号\n");
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
