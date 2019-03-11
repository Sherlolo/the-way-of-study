#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int m,n,temp;
    for(m = 1;m <= 9; m++)
    {
        for(n = 1; n < m; n++)
        {
            printf("    ");
        }
        for(n = m; n>=m&&n<=9; n++)
        {
            temp = m*n;
            printf("%4d",temp);
        }
        putchar('\n');
    }
    return 0;
}
