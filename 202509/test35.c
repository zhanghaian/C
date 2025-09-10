#include<stdio.h>

int main()
{
    double f;
    double c;
    printf("输入华氏温度：");
    scanf("%lf",&f);
    c = 5.0 / 9.0 * (f - 32);
    printf("c=%.2f\n",c);
    
    return 0;
}