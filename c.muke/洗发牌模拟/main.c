#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct card
{
    char suit[10];
    char face[10];
}CARD;
void fillcard(CARD card[]);         //°´Ë³Ðò±£³Ö¿¨ÅÆ
void deal(CARD card[],int result[]);//Êä³ö¿¨ÅÆ
void initialilze(int result[]);     //³õÊ¼»¯Ë³Ðò
void shuffle(int result[]);         //Ï´ÅÆ

int main(void)
{
    CARD card[52];
    fillcard(card);
    Deal(card);
    return 0;
}

void fillcard(CARD card[])
{
    char *psuit[] = {""}
}
