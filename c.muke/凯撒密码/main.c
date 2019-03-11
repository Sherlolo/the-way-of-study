#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
void Caesar(char c[]);

int main(void)
{
    char str[100];
    printf("Input a string:");
    gets(str);
    Caesar(str);
    puts(str);
    return 0;
}

void Caesar(char c[])
{
    int i = 0;
    while(c[i] != '\0')
    {
        c[i] = c[i] + 3;
        i++;
    }
}
