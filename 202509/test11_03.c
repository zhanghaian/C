#include<stdio.h>

int main()
{
    int a,b,difference;

    printf("输入的第一个整数:");
    scanf("%d",&a);
    printf("输入的第二个整数:");
    scanf("%d",&b);

    difference = a - b;

    printf("%d*%d=%d\n",a,b,difference);

    return 0;
}