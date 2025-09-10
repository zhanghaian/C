#include<stdio.h>

int main()
{
    int a,b,c;

    printf("输入的第一个整数:");
    scanf("%d",&a);
    printf("输入的第二个整数:");
    scanf("%d",&b);

    c = a * b;

    printf("%d*%d=%d\n",a,b,c);

    return 0;
}