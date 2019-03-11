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
void Addup(WIN stu[], int n);       //赋值
void Findship(WIN *pt); //计算出奖学金

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
输入学生人数提示："Input n:"
输入学生姓名提示："Input name:"
输入学生期末平均成绩提示："Input final score:"
输入学生班级评议成绩提示："Input class score:"
输入是否为学生干部提示："Class cadre or not?(Y/N):"
输入是否为西部学生提示："Students from the West or not?(Y/N):"
输入发表文章数量提示："Input the number of published papers:"
输入格式：
    输入学生人数："%d"
    输入学生姓名："%s"
    输入学生成绩："%d"
    输入是否为学生干部：" %c" （注意：%c前面有一个空格）
    输入是否为西部学生：" %c" （注意：%c前面有一个空格）
    输入发表文章数量： "%d"
输出格式
     输出学生获得的奖学金：  "name:%s,scholarship:%d\n"
     输出获得奖学金总数最高的学生："%s get the highest scholarship %d\n"
*/
