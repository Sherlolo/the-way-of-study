#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct clock

{

    int hour;

    int minute;

    int second;

} CLOCK;
CLOCK CalculateTime(CLOCK t1, CLOCK t2);

int main(void)
{
    CLOCK t1, t2, t;
    printf("Input time one:(hour£¬minute):");
    scanf("%d,%d",&t1.hour,&t1.minute);
    printf("Input time two: (hour£¬minute):");
    scanf("%d,%d",&t2.hour,&t2.minute);
    t = CalculateTime(t1,t2);
    printf("%dhour,%dminute\n",t.hour,t.minute);
    return 0;
}

CLOCK CalculateTime(CLOCK t1, CLOCK t2)
{
    int x1, x2, y;
    CLOCK t;
    x1 = t1.hour * 60 + t1.minute;
    x2 = t2.hour * 60 + t2.minute;
    y = abs(x1 - x2);
    t.hour = y / 60;
    t.minute = y % 60;
    return t;
}
