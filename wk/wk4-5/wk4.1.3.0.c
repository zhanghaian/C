#include <stdio.h>
//do-while循环,进入循环的时候不检查，而是在执行一轮循环的代码之后再来检查是否满足
int main() {
    int x = 0;
    int n = 0;

    scanf("%d", &x);
    do 
    {
        n++;
        x /= 10;
    } while (x > 0);
    printf("%d\n", n);
    return 0;
}