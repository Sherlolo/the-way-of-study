#include <stdio.h>

int main(void)
{
    int i,j,n;
    char c;
    printf("Please input a capital:\n");
    do{
        scanf("%c",&c);
    }while(c < 'A' || c > 'Z');
    n = c - 'A' + 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i; j++)
            printf(" ");
        for(j = 0; j <= i; j++)
            printf("%c",'A'+j);
        for(j = 1; j <= i; j++)
            printf("%c",'A'+ i - j);
        printf("\n");
    }
    return 0;
}
