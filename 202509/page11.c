#include<stdio.h>

int main()
{
    int a,b,sum;
    //用户输入两个整数
    printf("输入第一个整数:");
    scanf("%d",&a);
    printf("输入第二个整数:");
    scanf("%d",&b);

    //计算两个整数的和
    sum = a + b;

    //输出结果
    printf("%d+%d=%d\n",a,b,sum);

    return 0;
}