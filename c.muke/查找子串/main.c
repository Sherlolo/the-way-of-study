#include <stdio.h>
#include <string.h>
#define N 80
int SearchString(char s[], char d[]);

int main(void)
{
    char str1[N], str2[N];
    int y;
    printf("Input a string:");
    gets(str1);
    printf("Input another string:");
    gets(str2);
    y = SearchString(str1,str2);
    if(y == -1)
        printf("Not found!\n");
    else
        printf("Searching results:%d\n",y);
    return 0;
}

int SearchString(char s[], char d[])
{
    int i = 0;
    while(*(s+i)!='\0')
    {
        if(strncmp(s+i,d,strlen(d)) == 0)
        {
            return i+1;
        }
        i++;
    }
    return -1;
}


