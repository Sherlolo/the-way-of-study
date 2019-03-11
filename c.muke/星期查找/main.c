#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char weekday[][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char srt[10];
    int i, y = 0;
    printf("Please enter a string:\n");
    gets(srt);
    for(i = 0; i < 7; i++)
    {
        if(strcmp(weekday[i],srt) == 0)
        {
            y = i;
            break;
        }
    }
    if(y)
        printf("%s is %d\n",srt,y);
    else
        printf("Not found!\n");
    return 0;
}
