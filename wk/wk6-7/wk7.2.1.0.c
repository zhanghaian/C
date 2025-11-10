#include <stdio.h>

void sum ( int begain, int end );
//可以 void sum ( int , int ); 不会检查参数得名称
//函数的原型声明，告诉编译器有一个函数没有返回类型，根据声明来判断是不是正确的
//名称，参数，返回类型

int main() {
    sum(1,10);
    sum(20,30);
    sum(25,35);

    return 0;
}

void sum ( int begain, int end ) 
{
    int i;
    int sum = 0;
    for ( i = begain; i <= end; i++ ) {
        sum += i;
    }
    printf("%d到%d的和是%d\n", begain, end, sum);
}
//函数的定义