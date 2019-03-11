#include <stdio.h>
#include <stdlib.h>//??? NOTstblib.h
#define Maxsize 100000//MAXSIZE

int divideandconquer(int p[], int left, int right);
int max3(int a, int b, int c);

int main()
{
    int b, i, maxadd;
    //scanf("%d",&b);
    int a[Maxsize];
    scanf("%d", &b);
    for (i = 0; i<b; i++)
        scanf("%d", &a[i]);
    maxadd = divideandconquer(a, 0, b - 1);     //b-1
    printf("%d", maxadd);
    system("pause");    //Ϊ�˲��ý��׼˲����
    return 0;
}

int divideandconquer(int p[], int left, int right) {

    int mid, i;
    int leftmax, rightmax;
    int leftadd, rightadd;
    int leftaddmax, rightaddmax;
    leftaddmax = leftadd = 0;   //��������
    rightadd = rightaddmax = 0; //���鲻һ��������
    int max = 0;
    /*if(b<2){
    left=p[mid];
    right=p[mid+1];
    max=left>right?left:right;
    */
    if (left == right) {    //��ֹ����ֻ��һ������
        if (p[left]>0)  return p[left]; //����[i]
        else    return 0;
    }
    mid = (left + right) / 2;
    leftmax = divideandconquer(p, left, mid);       //��ֵ��
    rightmax = divideandconquer(p, mid + 1, right); //mid+1


    for (i = mid; i >= left; i--){  //NOT i>=0  i�����⣨forѭ�������ˣ���
        leftadd += p[i];    //NOT p[mid]
        if (leftadd>leftaddmax)
            leftaddmax = leftadd;
    }

    for (i = mid + 1; i <= right; i++) {    //NOT i>=0
        rightadd += p[i];   //NOT p[mid]
        if (rightadd>rightaddmax)
            rightaddmax = rightadd;
    }

    return max3(leftmax, rightmax, leftaddmax + rightaddmax);
}

int max3(int a, int b, int c) {
    return a>b ? (a>c ? a : c) : (b>c ? b : c);     //�����ľͺʹ�ıȽϣ����ſ�ʡ��
}
