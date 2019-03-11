#include <stdio.h>
#include <string.h>
#define N 80
int IsSubString(char a[], char b[]);

int main(void)
{
    char str1[N], str2[N];
    printf("Input the first string:");
    gets(str1);
    printf("Input the second string:");
    gets(str2);
    if(IsSubString(str1,str2))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

int IsSubString(char a[], char b[])
{
    int i = 0;
    while(*(a+i)!='\0')
    {
        if(strncmp(a+i,b,strlen(b)) == 0)
        {
            return 1;
        }
        i++;
    }
    return 0;
}


