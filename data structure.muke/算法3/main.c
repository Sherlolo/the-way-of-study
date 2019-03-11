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
    system("pause");    //为了不让结果准瞬即逝
    return 0;
}

int divideandconquer(int p[], int left, int right) {

    int mid, i;
    int leftmax, rightmax;
    int leftadd, rightadd;
    int leftaddmax, rightaddmax;
    leftaddmax = leftadd = 0;   //放这试试
    rightadd = rightaddmax = 0; //两遍不一样！！！
    int max = 0;
    /*if(b<2){
    left=p[mid];
    right=p[mid+1];
    max=left>right?left:right;
    */
    if (left == right) {    //终止条件只有一个数字
        if (p[left]>0)  return p[left]; //不是[i]
        else    return 0;
    }
    mid = (left + right) / 2;
    leftmax = divideandconquer(p, left, mid);       //赋值给
    rightmax = divideandconquer(p, mid + 1, right); //mid+1


    for (i = mid; i >= left; i--){  //NOT i>=0  i有问题（for循环后多加了；）
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
    return a>b ? (a>c ? a : c) : (b>c ? b : c);     //输出大的就和大的比较，括号可省略
}
