#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct card
{
    char suit[10];
    char face[10];
}CARD;
void fillcard(CARD card[]);         //��˳�򱣳ֿ���
void deal(CARD card[],int result[]);//�������
void initialilze(int result[]);     //��ʼ��˳��
void shuffle(int result[]);         //ϴ��

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
