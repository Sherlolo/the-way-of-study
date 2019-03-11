#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char c;
    printf("please input the first letter of someday:\n");
    scanf("%c",&c);
    if(c>='A' && c<='Z')
        c = c - 'A' + 'a';
    switch(c)
    {
    case 'm':
        printf("monday\n");
        break;
    case 't':
        printf("please input second letter:\n");
        scanf(" %c",&c);
        if(c>='A' && c<='Z')
        c = c - 'A' + 'a';
        switch(c)
        {
        case 'u':
            printf("tuesday\n");
            break;
        case 'h':
            printf("thursday\n");
            break;
        default:
            printf("data error\n");
            break;
        }
        break;
    case 'w':
        printf("wednesday\n");
        break;
    case 'f':
        printf("friday\n");
        break;
    case 's':
        printf("please input second letter:\n");
        scanf(" %c",&c);
        if(c>='A' && c<='Z')
        c = c - 'A' + 'a';
        switch(c)
        {
        case 'a':
            printf("saturday\n");
            break;
        case 'u':
            printf("sunday\n");
            break;
        default:
            printf("data error\n");
            break;
        }
        break;
    default:
        printf("data error\n");
        break;
    }
    return 0;
}
